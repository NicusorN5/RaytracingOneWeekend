#include "Plane.hpp"

std::optional<HitResult> Plane::hit(const Ray& r) const
{
    // https://stackoverflow.com/questions/23975555/how-to-do-ray-plane-intersection
    double denom = Vec3::dot( normal , r.Direction);

    // Prevent divide by zero:
    if (abs(denom) <= 1e-4f)
        return std::nullopt;

    // If you want to ensure the ray reflects off only
    // the "top" half of the plane, use this instead:
    //
    // if (-denom <= 1e-4f)
    //     return std::nullopt;

    float t = -(Vec3::dot(normal, r.Origin) + d) / Vec3::dot(normal, r.Direction);

    // Use pointy end of the ray.
    // It is technically correct to compare t < 0,
    // but that may be undesirable in a raytracer.
    if (t <= 1e-4)
        return std::nullopt;

    return HitResult{
        .t = t,
        .normal = normal
    };
}
