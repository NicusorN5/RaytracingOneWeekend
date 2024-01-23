#pragma once
#include <numeric>
#include <limits>
#include <concepts>
#include <numbers>
#include <random>

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

inline std::random_device rnddev;

template<std::floating_point T>
T random_floating_point(T min, T max)
{
	std::uniform_real_distribution<T> dist(min, max);
	return dist(rnddev);
}