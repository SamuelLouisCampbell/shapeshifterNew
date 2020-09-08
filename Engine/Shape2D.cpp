#include "Shape2D.h"

const std::vector<Vec2f> Shape2D::GetShape() const
{
	auto poly = shape;
	for (auto& v : poly)
	{
		v *= scale;
		v += pos;
	}
	return poly;
}

const Color& Shape2D::GetColor() const
{
	return shapeCol;
}

const Vec2f Shape2D::GetPos() const
{
	return pos;
}

Vec2f Shape2D::SetPos(Vec2f newPos)
{
	return pos += newPos;
}

const float Shape2D::GetScale() const
{
	return scale;
}

void Shape2D::SetScale(float newScale)
{
	scale = newScale;
}

const float Shape2D::GetRotation() const
{
	return rotation;
}

void Shape2D::SetRoation(float newRotation)
{
	rotation = newRotation;
}
