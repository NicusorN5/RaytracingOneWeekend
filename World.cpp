#include "World.hpp"
#include "Object.hpp"

Object* World::at(size_t i)
{
	return objects.at(i).get();
}

Color World::hit(const Ray& r) const
{
	for (auto& obj : objects)
	{
		auto ray_result = obj->hit(r);
		if (ray_result.has_value())
		{
			auto t = ray_result.value();
			return obj->material->hit(r.at(t.t), t.normal );
		}
	}

	Vec3 unit_direction = Vec3::normalize(r.Direction);
	auto a = 0.5 * (unit_direction.Y + 1.0);
	return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}
