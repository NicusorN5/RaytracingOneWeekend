#include "NormalMaterial.hpp"
#include <algorithm>

Color NormalMaterial::hit(const Vec3& point, const Vec3& norm) const
{
	return 0.5 * Color{
		norm.X,
		norm.Y,
		norm.Z,
		1.0
	} + Color{ 0.5, 0.5, 0.5 , 0};
}

void NormalMaterial::scatter(std::vector<Ray>, const Vec3&, const Vec3&)
{
}
