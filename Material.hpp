#pragma once
#include "Ray.hpp"
#include "Color.hpp"
#include <vector>

class Material
{
protected:
	Material() = default;
public:
	virtual Color hit(const Vec3& point, const Vec3& norm) const = 0;
	virtual void scatter(std::vector<Ray> newRays, const Vec3& point, const Vec3& norm) = 0;
	virtual ~Material() = default;
};

template<typename T>
concept material_type = std::is_base_of_v<Material, T>;