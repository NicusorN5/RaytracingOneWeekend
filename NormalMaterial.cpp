#include "NormalMaterial.hpp"
#include <algorithm>

Color NormalMaterial::hit(const Vec3& point, const Vec3& norm) const
{
	return
	{
		static_cast<uint8_t>(std::clamp<int>(norm.X * 255, 0, 255)),
		static_cast<uint8_t>(std::clamp<int>(norm.Y * 255, 0, 255)),
		static_cast<uint8_t>(std::clamp<int>(norm.Z * 255, 0, 255)),
		255
	};
}
