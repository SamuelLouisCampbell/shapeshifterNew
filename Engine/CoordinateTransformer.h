#pragma once
#include <vector>
#include "Vec2.h"
#include "Graphics.h"

class CoordinateTransformer
{
public: 
	CoordinateTransformer(Graphics& gfx)
		:
		gfx(gfx)
	{}

	void DrawClosedPolyline(const std::vector<Vec2>& verts, Color c = Colors::Cyan)
	{
		std::vector<Vec2> copy = verts;
		Vec2 offset = { float(Graphics::ScreenWidth / 2), float(Graphics::ScreenHeight / 2) };
		for (auto& v : copy)
		{
			v.y *= -1.0f;
			v += offset;
		}
		gfx.DrawClosedPolyLine(copy, c);
	}
private: 
	Graphics& gfx;
};