#include "Triangle.h"

Triangle::Triangle(float initialScale, float initialRotation, Vec2f initialPosition, Color col_in)
{
	rotation = initialRotation;
	scale = initialScale;
	posTransform = initialPosition;
	shapeCol = col_in;

	shape.push_back({ 0.0f, 0.0f });
	shape.push_back({ 1.0f, 0.0f });
	shape.push_back({ 0.5f, 0.86603f });

}
