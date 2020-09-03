#include "Shape2D.h"

const std::vector<Vec2f>& Shape2D::GetShape() const
{
	return shape;
}

const Color& Shape2D::GetColor() const
{
	return shapeCol;
}

const Vec2f Shape2D::GetTransform() const
{
	return posTransform;
}

Vec2f Shape2D::SetTransform(Vec2f& newPos)
{
	return posTransform = newPos;
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
