#include "Ray.hpp"

Vec3 Ray::at(double t) const
{
	return Origin + t * Direction;
}
