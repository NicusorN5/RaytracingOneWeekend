// RaytracingOneWeekend.cpp : Defines the entry point for the application.
//
#include <print>
#include <iostream>
#include <fstream>
#include <ranges>

#include "PPMImage.hpp"
#include "Object.hpp"
#include "World.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"

PPMImage render(const Camera& cam, World& world)
{
	PPMImage image(cam.screen_size.X, cam.screen_size.Y);

	for (int j = 0; j < cam.screen_size.Y; j++)
	{
		for (int i = 0; i < cam.screen_size.X; i++)
		{
			
		}
	}
}

auto main() -> int
{
	Camera camera;
	camera.fov = to_radians(65.0);

	World world;
	world.add<Sphere>(Vec3{ 0, 0, 0 }, 1);
}