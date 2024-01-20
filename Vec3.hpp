#pragma once
#include <concepts>

template<std::floating_point T>
struct Vec3
{
	T X, Y, Z;

	Vec3 operator +=(const Vec3& v)
	{
		return { X + v.X, Y + v.Y, Z + v.Z };
	}
	Vec3 operator +(const Vector3& v) const
	{
		return { X + v.X, Y + v.Y, Z + v.Z };
	}

	Vec3 operator -=(const Vector3& v)
	{
		return { X + v.X, Y + v.Y, Z + v.Z };
	}

	Vec3 operator -(const Vector3& v)
	{
		return { X - v.X, Y - v.Y, Z - v.Z };
	}

	static T dot(const Vec3& a, const Vec3& b)
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}
};