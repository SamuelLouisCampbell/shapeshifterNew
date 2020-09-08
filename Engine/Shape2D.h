#pragma once
#include "Vec2.h"
#include <vector>
#include "Colors.h"
#include "ChiliMath.h"

class Shape2D
{
public:
	const std::vector<Vec2f> GetShape() const;
	const Color& GetColor() const;
	const Vec2f GetPos() const;
	Vec2f SetPos(Vec2f newPos);
	const float GetScale() const;
	void SetScale(float newScale);
	const float GetRotation() const;
	void SetRoation(float newRotation);

protected:
	Color shapeCol;
	std::vector<Vec2f> shape;
	Vec2f pos = {0.0f, 0.0f};
	float scale = 1.0f;
	float rotation = 0.0f;
};

