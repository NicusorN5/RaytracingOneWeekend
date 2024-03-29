#pragma once
#include "Material.hpp"

class NormalMaterial : public Material
{
public:
	NormalMaterial() = default;
	// Inherited via Material
	Color hit(const Vec3& point, const Vec3& norm) const override;
	void scatter(std::vector<Ray>, const Vec3&, const Vec3&) override;
};