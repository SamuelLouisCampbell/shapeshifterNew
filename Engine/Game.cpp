/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <ft2build.h>
#include FT_FREETYPE_H


Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    ct(gfx),
    tri0(300.0f, 0.0f, { 0.0f, 100.0f }, Colors::Magenta),
    plank0({ 100.0f,0.0f }, 300.0f, 600.0f, 9.0f),
    spawn(balls, 20.0f, { -0.0f, -250.0f }, -150.0f, 100.0f, 200.0f, 1.0f)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}



void Game::UpdateModel()
{
    float dt = ft.Mark();

    
  
 
    for (auto& b : balls)
    {
        const auto plankVector = plank0.GetPlankSurfaceVector();
        const auto PlankNormal = Vec2{ plankVector.y,-plankVector.x };
        const auto ballPos = b.GetPos();
        const auto plankPts = plank0.GetPoints();

        if (PlankNormal * b.GetVelocity() < 0.0f)
        {
            if (DistancePointsLine(plankPts.first, plankPts.second, b.GetPos()) < b.GetScale())
            {
                const Vec2 w = plank0.GetPlankSurfaceVector().GetNormalized();
                const Vec2 v = b.GetVelocity();
                //dot product for collision
                b.SetVelocity(w * (v * w) * 2.0f - v);
                collisionSound.Play();
            }
        }
      

        b.Update(dt);
    }
    spawn.Update(dt);
    const auto new_end = std::remove_if(balls.begin(), balls.end(),
        [this](const Ball& b)
        {
            return b.GetPos().LenSq() > sq(maxBallDist);
        });
    balls.erase(new_end, balls.end());



    myFont.ComputeString(std::to_string(spawn.GetTime()));
    //move tri
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        tri0.SetPos({ speed, 0.0f});
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        tri0.SetPos({ -speed, 0.0f });
    }
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        tri0.SetPos({ 0.0f, speed });
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        tri0.SetPos({ 0.0f, -speed });
    }
    //move paddle
    if (wnd.kbd.KeyIsPressed('W'))
    {
        plank0.SetFreeY(plank0.GetFreePt().y + speed);
    }
    if (wnd.kbd.KeyIsPressed('S'))
    {
        plank0.SetFreeY(plank0.GetFreePt().y - speed);
    }
    //scale tri
    while (!wnd.mouse.IsEmpty())
    {
        const auto e = wnd.mouse.Read();
        if (e.GetType() == Mouse::Event::Type::WheelUp)
        {
            tri0.SetScale(tri0.GetScale() * 1.05f);
        }
        else if (e.GetType() == Mouse::Event::Type::WheelDown)
        {
            tri0.SetScale(tri0.GetScale() * 0.95f);
        }  
    }
}

void Game::ComposeFrame()
{
    //ct.DrawClosedPolyline(tri0.GetShape(), tri0.GetColor());
   
    ct.DrawClosedPolyline(plank0.GetShape(), plank0.GetColor());
    
    for (auto& b : balls)
    {
        ct.DrawClosedPolyline(b.GetShape(), b.GetColor());
    }

    Vec2f pos = { 50, 50 };
    myFont.RenderString(gfx,pos, 1.0f);
}
