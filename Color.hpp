#pragma once
#include <cstdint>

struct Color
{
	double R, G, B, A;

	Color operator+(const Color& c) const;
	Color& operator+=(const Color& c);

	Color operator *(const double s) const;
	Color operator *(const Color& c) const;
};

Color operator*(const double s, const Color& c);