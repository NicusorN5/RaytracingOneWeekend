// RaytracingOneWeekend.cpp : Defines the entry point for the application.
//
#include <print>
#include <fstream>
#include <ranges>

#include "PPMImage.hpp"

auto write_gradient_image()
{
	constexpr int image_width = 256;
	constexpr int image_height = 256;

	std::ofstream file("image.ppm");
	PPMImage image(image_width, image_height);

	for (int j : std::views::iota(0, image_height))
	{
		for (int i : std::views::iota(0, image_width))
		{
			double r = static_cast<double>(i) / (image_width - 1);
			double g = static_cast<double>(j) / (image_height - 1);

			image.at(i, j) = Color
			{
				.R = static_cast<uint8_t>(255 * i),
				.G = static_cast<uint8_t>(255 * j),
				.B = 0 
			};

			//std::print("progress - i = {}, j = {} \r\n", i, j);
		}
	}

	file << image;
}

auto main() -> int
{
	write_gradient_image();
}