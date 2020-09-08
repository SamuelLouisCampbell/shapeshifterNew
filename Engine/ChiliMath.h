/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	ChiliMath.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once
#include <cmath>
#include <math.h>
#include "Vec2.h"

constexpr float PI = 3.14159265f;
constexpr double PI_D = 3.1415926535897932;

template <typename T>
inline auto sq(const T& x)
{
	return x * x;
}

template<typename T> 
inline T ReturnDiv2(T number)
{
	return T / T(2.0f);
}

template<typename T>
inline T DistancePointsLine(const _Vec2<T>& p0, const _Vec2<T>& p1, const _Vec2<T>& q)
{
	const T a = p0.y - p1.y;
	const T b = p1.x - p0.x;
	const T c = p0.x * p1.y - p1.x * p0.y;

	return std::abs(a * q.x + b * q.y + c) / std::sqrt(sq(a) + sq(b));
}

template<typename T>
inline float ToRadians(T angleDegs)
{
	return angleDegs * (PI / 180.0f);
}

template<typename T>
inline float ToDegrees(T angleRads)
{
	return angleRads * (180.0f / PI);
}

template<typename T>
inline T wrap_angle( T theta )
{
	const T modded = fmod( theta,(T)2.0 * (T)PI_D );
	return (modded > (T)PI_D) ?
		(modded - (T)2.0 * (T)PI_D) :
		modded;
}

template<class T>
T Clamp( const T &Value, const T &MinValue, const T &MaxValue )
{
	return std::max( MinValue, std::min( MaxValue, Value ) );
}