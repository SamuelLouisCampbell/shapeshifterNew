#pragma once
#include "Ball.h"
#include <random>

class BallSpawn
{
public:
	BallSpawn(std::vector<Ball>& container, float radius, Vec2f pos, float minVx, float maxVx, float vy, float period)
		:
		pos(pos),
		radius(radius),
		vxDist(minVx, maxVx),
		period(period),
		vy(vy),
		container(container)
	{}

	void Update(float dt)
	{
		time += dt;
		if (time >= period)
		{
			time = 0.0f;
			container.emplace_back(pos, radius, 0.0f, Vec2{ vxDist(rng), vy }, Colors::Red);
		}
	}

	float GetTime() const
	{
		return time;
	}

private:
	std::mt19937 rng = std::mt19937(std::random_device{}());
	std::uniform_real_distribution<float> vxDist;
	Vec2f pos;
	float period;
	float vy;
	std::vector<Ball>& container;
	float radius;
	float time = period;
};