#include "Vec3.hpp"
#include "Vec3.hpp"
#include <cmath>

Vec3 Vec3::operator+=(const Vec3& v)
{
	X += v.X;
	Y += v.Y;
	Z += v.Z;
	return *this;
}

Vec3 Vec3::operator+(const Vec3& v) const
{
	return { X + v.X, Y + v.Y, Z + v.Z };
}

Vec3 Vec3::operator-() const
{
	return Vec3(
		-X, 
		-Y
	);
}

Vec3 Vec3::operator-=(const Vec3& v)
{
	X -= v.X;
	Y -= v.Y;
	Z -= v.Z;
	return *this;
}

Vec3 Vec3::operator-(const Vec3& v) const
{
	return { X - v.X, Y - v.Y, Z - v.Z };
}

Vec3 Vec3::operator*=(const double s)
{
	X *= s;
	Y *= s;
	Z *= s;
	return *this;
}

Vec3 Vec3::operator*(const double s) const
{
	return { X * s, Y * s, Z * s };
}

Vec3 Vec3::operator/=(const double s)
{
	X /= s;
	Y /= s;
	Z /= s;
	return *this;
}

Vec3 Vec3::operator/(const double s) const
{
	return { X / s, Y / s, Z / s };
}

double Vec3::dot(const Vec3& a, const Vec3& b)
{
	return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

double Vec3::length(const Vec3& v)
{
	return sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
}

double Vec3::length_squared(const Vec3& v)
{
	return v.X * v.X + v.Y * v.Y + v.Z * v.Z;
}

Vec3 Vec3::cross(const Vec3& v1, const Vec3& v2)
{
	//Copied from: https://github.com/NicusorN5/3D_Rad_Space/blob/master/3DRadSpace/Engine3DRadSpace/Math/Vector3.cpp
	return Vec3{
		v1.Y * v2.Z - v1.Z * v2.Y,
		v1.Z * v2.X - v1.X * v2.Z,
		v1.X * v2.Y - v1.Y * v2.X
	};
}

Vec3 Vec3::normalize(const Vec3& v)
{
	return v / Vec3::length(v);
}

Vec3 Vec3::hadamard(const Vec3& a, const Vec3& b)
{
	return
	{
		a.X * b.X,
		a.Y * b.Y,
		a.Z * b.Z,
	};
}

Vec3 operator*(const double s, const Vec3& v)
{
	return { s * v.X, s * v.Y, s * v.Z };
}

Vec3 operator/(const double s, const Vec3& v)
{
	return { s / v.X, s / v.Y, s / v.Z };
}
