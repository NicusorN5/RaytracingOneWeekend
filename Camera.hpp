#pragma once
#include "Vec3.hpp"
#include "Utility.hpp"
#include "Point.hpp"

struct Camera
{
	Vec3 origin = { 0,0,0 };
	Vec3 normal = { 0,1,0 };
	Vec3 direction = { 0,0, -1 }; //-Z = forward

	double fov = to_radians(65.0);
	double focal_length = 1.0;
	double viewport_height = 2.0f;

	Point<unsigned> screen_size;

	double viewport_width() const;

	Vec3 right() const;

	Vec3 viewport_u() const;
	Vec3 viewport_v() const;

	Vec3 pixel_delta_u() const;
	Vec3 pixel_delta_v() const;
};