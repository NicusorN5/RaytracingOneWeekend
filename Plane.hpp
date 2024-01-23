#pragma once
#include "Object.hpp"

class Plane : public Object
{
public:
	template<material_type M>
	Plane(Vec3 norm, double dist, M&& mat) :
		Object(std::move(mat)),
		normal(norm),
		d(dist)
	{
	}

	std::optional<HitResult> hit(const Ray& r) const override;

	Vec3 normal;
	double d;
};