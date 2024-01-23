#include "DiffuseMaterial.hpp"

DiffuseMaterial::DiffuseMaterial(Color diffuseColor, double reflq) :
	color(diffuseColor),
	reflected_quantity(reflq)
{
}

Color DiffuseMaterial::hit(const Vec3& point, const Vec3& norm) const
{
	//return color * reflected_quantity * Vec3::dot(norm, )
}

void DiffuseMaterial::scatter(std::vector<Ray> newRays, const Vec3& point, const Vec3& norm)
{
	Vec3 newR = Vec3::random_unit();
	if (Vec3::dot(newR, norm) < 0)
		newR *= -1;

	newRays.push_back(
		Ray{
			.Origin = point,
			.Direction = newR
		}
	);
}
