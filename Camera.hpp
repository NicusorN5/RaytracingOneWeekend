#pragma once
#include "Vec3.hpp"
#include "Utility.hpp"
#include "Point.hpp"

struct Camera
{
	Vec3 origin = { 0,0,0 };
	Vec3 normal = { 0,1,0 };
	Vec3 direction = { 0,0, -1 }; //-Z = forward

	float fov = to_radians(65.0);
	float focal_length = 1.0;
	float viewport_height = 2.0f;

	Point<unsigned> screen_size;

	float viewport_width();

	Vec3 right();

	Vec3 viewport_u();
	Vec3 viewport_v();

	Vec3 pixel_delta_u();
	Vec3 pixel_delta_v();
};