#pragma once
#include "Object.hpp"

class Sphere : public Object
{
public:
	template<material_type M>
	Sphere(const Vec3& c, const double r, M&& m):
		Object(std::move(m)),
		center(c),
		radius(r)
	{
	}

	double radius;
	Vec3 center;

	std::optional<HitResult> hit(const Ray& r) const override;
};	