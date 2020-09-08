#include "Triangle.h"
#include <cmath>

Triangle::Triangle(float initialScale, float initialRotation, Vec2f initialPosition, Color col_in)
{
	rotation = initialRotation;
	scale = initialScale;
	pos = initialPosition;
	shapeCol = col_in;


	//Create a unit Triangle
	const float dTheta = 2.0f * 3.14159f / 3.0f;
	shape.reserve(3);
	for (int i = 0; i < 3; i++)
	{
		shape.emplace_back(
			1 * std::cos(float(i) * dTheta),
			1 * std::sin(float(i) * dTheta)
			);
	}

}
