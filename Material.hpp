#pragma once
#include "Vec3.hpp"
#include "Color.hpp"

class Material
{
protected:
	Material() = default;
public:
	virtual Color hit(const Vec3& point, const Vec3& norm) const = 0;
	virtual ~Material() = default;
};

template<typename T>
concept material_type = std::is_base_of_v<Material, T>;