#include "Ball.h"

Ball::Ball(Vec2 pos_in, float radius, float initialRotation, Vec2 vel, Color c)
	:
	velocity(vel)
{
		rotation = initialRotation;
		scale = radius;
		pos = pos_in;
		shapeCol = c;

		//Create a unit Circle
		const float dTheta = 2.0f * 3.14159f / 32.0f;
		shape.reserve(3);
		for (int i = 0; i < 32; i++)
		{
			shape.emplace_back(
				1 * std::cos(float(i) * dTheta),
				1 * std::sin(float(i) * dTheta)
			);
		}

}

Vec2 Ball::GetVelocity() const
{
	return velocity;
}

void Ball::SetVelocity(const Vec2& vel_in)
{
	velocity = vel_in;
}

void Ball::Update(float dt)
{
	SetPos(velocity * dt);
}
