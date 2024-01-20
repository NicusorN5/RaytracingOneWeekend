#include "Sphere.hpp"

Sphere::Sphere(const Vec3& c, const double r) : 
	center(c),
	radius(r)
{
}

std::optional<HitResult> Sphere::hit(const Ray& r) const
{
	//Copied from https://github.com/NicusorN5/3D_Rad_Space/blob/master/3DRadSpace/Engine3DRadSpace/Math/Ray.cpp
	float a = Vec3::dot(r.Direction, r.Origin - center);
	float nabla = powf(a, 2) - (Vec3::length_squared(r.Origin - center) - powf(radius, 2));

	if (nabla < 0) return std::nullopt;

	double t = -a - sqrtf(nabla);
	return HitResult{
		t,
		Vec3::normalize(r.at(t) - center)
	};
}
