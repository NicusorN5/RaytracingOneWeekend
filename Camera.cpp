#include "Camera.hpp"

double Camera::viewport_width() const
{
	return viewport_height * (static_cast<double>(screen_size.X) / screen_size.Y);
}

Vec3 Camera::right() const
{
	return Vec3::cross(normal, direction);
}

Vec3 Camera::viewport_u() const
{
	return Vec3(viewport_width(), 0, 0);
}

Vec3 Camera::viewport_v() const
{
	return Vec3(0, -viewport_height, 0);
}

Vec3 Camera::pixel_delta_u() const
{
	return viewport_u() / screen_size.X;
}

Vec3 Camera::pixel_delta_v() const
{
	return viewport_v() / screen_size.Y;
}
