#pragma once
#include "Vec3.hpp"

struct Ray
{
	Vec3 Origin;
	Vec3 Direction;

	Vec3 at(float t) const;
};