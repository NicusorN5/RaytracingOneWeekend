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
#include "NormalMaterial.hpp"
#include "Plane.hpp"
#include "PlainMaterial.hpp"

PPMImage render(const Camera& cam, World& world)
{
	PPMImage image(cam.screen_size.X, cam.screen_size.Y);

	auto viewport_upper_left = cam.origin - Vec3(0, 0, cam.focal_length) - cam.viewport_u() / 2 - cam.viewport_v() / 2;
	auto pixel00_loc = viewport_upper_left + 0.5 * (cam.pixel_delta_u() + cam.pixel_delta_v());

	for (unsigned j = 0; j < cam.screen_size.Y; j++)
	{
		std::print(std::clog, "Scanline {} \r\n", j);
		for (unsigned i = 0; i < cam.screen_size.X; i++)
		{
			auto pixel_center = pixel00_loc + (i * cam.pixel_delta_u()) + (j * cam.pixel_delta_v());
			auto ray_direction = pixel_center - cam.origin;
			Ray r{
				.Origin = cam.origin,
				.Direction = ray_direction
			};
			
			//initial sky write
			Vec3 unit_direction = Vec3::normalize(r.Direction);
			auto a = 0.5 * (unit_direction.Y + 1.0);
			image.write(i, j, 0.0, Color{(1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0),});

			for (auto obj : world)
			{
				auto ray_result = obj->hit(r);
				if (ray_result.has_value())
				{
					auto t = ray_result.value();
					image.write(i, j, t.t, obj->material->hit(r.at(t.t), t.normal));
				}
			}

		}
	}

	return image;
}

auto main() -> int
{
	Camera camera;
	camera.screen_size = { 800, 600 };
	camera.fov = to_radians(65.0);

	World world;
	//world.add<Sphere>(Vec3{ 0, 1, -2 }, 1, NormalMaterial());
	//world.add<Sphere>(Vec3{ 0, 0, -2 }, 1, NormalMaterial());
	world.add<Plane>(Vec3(0, 1, 0), 2, PlainMaterial(Color(1.0, 0.6, 0.6, 1.0)));
	world.add<Sphere>(Vec3{ 0, -1, -5 }, 3, NormalMaterial());

	std::ofstream image("my_image.ppm");
	image <<  render(camera, world);
	return 0;
}