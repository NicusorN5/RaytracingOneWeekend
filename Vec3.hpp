#pragma once
#include <concepts>

struct Vec3
{
	double X, Y, Z;

	Vec3 operator +=(const Vec3& v);
	Vec3 operator +(const Vec3& v) const;

	Vec3 operator -=(const Vec3& v);
	Vec3 operator -(const Vec3& v) const;

	Vec3 operator *=(const double s);
	Vec3 operator *(const double s) const;

	Vec3 operator /=(const double s);
	Vec3 operator /(const double s) const;

	static double dot(const Vec3& a, const Vec3& b);
	static double length(const Vec3& v);
	static double length_squared(const Vec3& v);
	static Vec3 cross(const Vec3& a, const Vec3& b);
	static Vec3 normalize(const Vec3& v);
	static Vec3 hadamard(const Vec3& a, const Vec3& b);
};

Vec3 operator *(const double s, const Vec3& v);
Vec3 operator /(const double s, const Vec3& v);