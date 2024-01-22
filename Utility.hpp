#pragma once
#include <numeric>
#include <limits>
#include <concepts>
#include <numbers>

template<std::floating_point T>
constexpr T to_radians(T degrees)
{
	return std::numbers::pi_v<T> / T(180.0) * degrees;
}

template<std::floating_point T>
constexpr T to_degrees(T radians)
{
	return T(180.0) / std::numbers::pi_v<T> * radians;
}