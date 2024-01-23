#pragma once
#include "Material.hpp"

class PlainMaterial : public Material
{
public:
	PlainMaterial(Color c = {1,1,1,1});

	Color color;

	// Inherited via Material
	Color hit(const Vec3& point, const Vec3& norm) const override;
};