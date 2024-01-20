#include "Camera.hpp"

float Camera::viewport_width()
{
	return viewport_height * (static_cast<double>(screen_size.X) / screen_size.Y);
}

Vec3 Camera::right()
{
	Vec3::cross(normal, direction);
}

Vec3 Camera::viewport_u()
{
	return Vec3(viewport_width(), 0, 0);
}

Vec3 Camera::viewport_v()
{
	return Vec3(0, -viewport_height, 0);
}

Vec3 Camera::pixel_delta_u()
{
	return viewport_u() / screen_size.X;
}

Vec3 Camera::pixel_delta_v()
{
	return viewport_v() / screen_size.Y;
}
