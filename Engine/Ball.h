#pragma once
#include "Shape2D.h"

class Ball : public Shape2D
{
public:
	Ball(Vec2 pos_in, float radius, float initialRotation, Vec2 vel, Color c = Colors::Red);
	Vec2 GetVelocity() const;
	void SetVelocity(const Vec2& vel_in);
	void Update(float dt);
private:
	float radius;
	Vec2 velocity;
};