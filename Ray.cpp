#include "Ray.hpp"

Vec3 Ray::at(float t) const
{
	return Origin + t * Direction;
}
