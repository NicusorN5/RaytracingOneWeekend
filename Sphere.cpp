#include "Sphere.hpp"

std::optional<HitResult> Sphere::hit(const Ray& r) const
{
	Vec3 oc = r.Origin - center;
	auto a = Vec3::dot(r.Direction, r.Direction);
	auto b = 2.0 * Vec3::dot(oc, r.Direction);
	auto c = Vec3::dot(oc, oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;
	
	auto normal = Vec3::normalize(r.at(discriminant) - center);

	if (Vec3::dot(normal, r.Direction) < 0) return std::nullopt;

	if (discriminant >= 0)
	{
		return HitResult
		{
			discriminant,
			normal
		};
	}
	else return std::nullopt;
}
