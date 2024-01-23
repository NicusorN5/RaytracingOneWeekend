#include "PlainMaterial.hpp"

PlainMaterial::PlainMaterial(Color c):
	color{c}
{
}

Color PlainMaterial::hit(const Vec3& point, const Vec3& norm) const
{
	return this->color;
}
