#pragma once
#include <cstdint>

struct Color
{
	double R, G, B, A;

	Color operator+(const Color& c);
	Color operator *(const double s);
	Color operator *(const Color& c);
};

Color operator*(const double s, const Color& c);