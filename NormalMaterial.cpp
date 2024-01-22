#include "NormalMaterial.hpp"
#include <algorithm>

Color NormalMaterial::hit(const Vec3& point, const Vec3& norm) const
{
	return {
		norm.X,
		norm.Y,
		norm.Z,
		1.0
	};
}
