#pragma once
#include <memory>
#include <optional>

#include "Ray.hpp"
#include "Material.hpp"
#include "HitResult.hpp"

class Object
{
protected:
	template<material_type M>
	Object(M&& mat)
	{
		material.reset(new M(std::move(mat)));
	}
public:
	Object(const Object&) = delete;
	Object(Object&&) noexcept = default;

	std::unique_ptr<Material> material;

	virtual std::optional<HitResult> hit(const Ray& r) const = 0;
	virtual ~Object() = default;
};