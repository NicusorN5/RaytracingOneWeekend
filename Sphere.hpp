#pragma once
#include "Object.hpp"

class Sphere : public Object
{
public:
	Sphere(const Vec3& c, const double r);

	double radius;
	Vec3 center;

	std::optional<HitResult> hit(const Ray& r) const override;
};	