#pragma once
#include "Shape2D.h"
#include <algorithm>


class Plank : public Shape2D
{
public:
	Plank(Vec2 anchor, float clampMovement, float size, float width = 8.0f, Color c = Colors::Yellow )
		:
		clampMovement(clampMovement),
		size(size),
		width(width)
	{
		pos = anchor;
		freePtModel = Vec2f{ anchor.x - size, anchor.y };
		shapeCol = c;
		shape.reserve(4);
		shape.emplace_back(pos);
		shape.emplace_back(freePtModel);
		shape.emplace_back(Vec2f{ freePtModel.x, freePtModel.y + width});
		shape.emplace_back(Vec2f{ pos.x, pos.y + width });

	}
	Vec2 GetFreePt() const
	{
		return freePtModel + GetPos();
	}
	void SetFreeY(float freeY_in)
	{
		float clampUpper = pos.y + clampMovement;
		float clampLower = pos.y - clampMovement;

		if (freeY_in + pos.y < clampUpper && freeY_in - pos.y > clampLower)
		{
			freePtModel.y = freeY_in + pos.y;
		}
		shape[1] = freePtModel;
		shape[2] = freePtModel + Vec2(0.0f, width);
	
	}
	void MoveFreeY(float deltaY)
	{
		SetFreeY(GetFreePt().y + deltaY);
	}
	Vec2 GetPlankSurfaceVector() const
	{
		return -freePtModel;
	}
	auto GetPoints() const
	{
		const Vec2f pos = GetPos(); 
		return std::make_pair(pos, pos + freePtModel);
	}

private:
	float clampMovement;
	Vec2 freePtModel;
	float width;
	float size; 
};

