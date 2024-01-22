#pragma once
#include "Vec3.hpp"

struct Ray
{
	Vec3 Origin;
	Vec3 Direction;

	Vec3 at(double t) const;
};