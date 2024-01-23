#pragma once
#include "PPMImage.hpp"
#include "World.hpp"
#include <algorithm>

PPMImage::PPMImage(const unsigned _width, const unsigned _heigth) :
	width(_width),
	height(_heigth)
{
	auto size = width * height;
	image = std::make_unique<Color[]>(size);
	//zbuffer = std::make_unique<double[]>(size);
}

bool PPMImage::write(unsigned x, unsigned y, double z, Color c)
{
	const auto coord = width * y + x;
	//if (z >= zbuffer[coord])
	{
		at(x, y) = c;
		//zbuffer[coord] = z;
		return true;
	}
	return false;
}

Color& PPMImage::at(unsigned x, unsigned y)
{
	return image[width * y + x];
}

Color PPMImage::at(unsigned x, unsigned y) const
{
	return image[width * y + x];
}

unsigned PPMImage::get_width() const
{
	return width;
}

unsigned  PPMImage::get_height() const
{
	return height;
}

PPMImage::iterator::iterator(Color* p_col) : ptr(p_col)
{
}

Color& PPMImage::iterator::operator*()
{
	return *ptr;
}

Color* PPMImage::iterator::operator->()
{
	return ptr;
}

PPMImage::iterator& PPMImage::iterator::operator ++()
{
	ptr++;
	return *this;
}

PPMImage::iterator PPMImage::iterator::operator++(int)
{
	iterator copy = *this;
	ptr++;
	return copy;
}

PPMImage::iterator& PPMImage::iterator::operator --()
{
	ptr--;
	return *this;
}

PPMImage::iterator PPMImage::iterator::operator--(int)
{
	iterator copy = *this;
	ptr--;
	return copy;
}

PPMImage::iterator PPMImage::begin()
{
	return &image[0];
}

PPMImage::iterator PPMImage::end()
{
	return (&image[0]) + (width * height);
}

PPMImage::iterator PPMImage::begin() const
{
	return &image[0];
}

PPMImage::iterator PPMImage::end() const
{
	return (&image[0]) + (width * height);
}

std::ostream& operator <<(std::ostream& ostr, const PPMImage& image)
{
	ostr << "P3\r\n" << image.width << "\r\n" << image.height << "\r\n255\r\n";

	for (unsigned j = 0; j < image.height; j++)
	{
		for (unsigned i = 0; i < image.width; i++)
		{
			Color c = image.at(i, j);
#pragma warning(push)
#pragma warning(disable: 4244)
			ostr << std::clamp<int>(c.R * 255.999, 0, 255) << ' '
				<< std::clamp<int>(c.G * 255.999, 0, 255) << ' '
				<< std::clamp<int>(c.B * 255.999, 0, 255) << "\r\n";
#pragma warning(pop)
		}
	};

	return ostr;
}