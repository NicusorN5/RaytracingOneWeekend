#pragma once
#include <memory>
#include <optional>

#include "Ray.hpp"
#include "Material.hpp"
#include "HitResult.hpp"

class Object
{
protected:
	Object() = default;
public:
	Object(const Object&) = delete;
	Object(Object&&) noexcept = default;

	std::unique_ptr<Material> material;

	virtual std::optional<HitResult> hit(const Ray& r) const = 0;
	virtual ~Object() = default;
};