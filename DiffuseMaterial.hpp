#pragma once
#include "Material.hpp"

class DiffuseMaterial : public Material
{
public:
	DiffuseMaterial(Color diffuseColor = {1,1,1,1}, double reflq = 0.5);

	Color color;
	double reflected_quantity;

	// Inherited via Material
	Color hit(const Vec3& point, const Vec3& norm) const override;
	void scatter(std::vector<Ray> newRays, const Vec3& point, const Vec3& norm) override;
};