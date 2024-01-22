#pragma once
#include "PPMImage.hpp"
#include "World.hpp"
#include <algorithm>

PPMImage::PPMImage(const unsigned _width, const unsigned _heigth) :
	width(_width),
	height(_heigth)
{
	image = std::make_unique<Color[]>(width * height);
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

	for (Color& c : image)
	{
#pragma warning(push)
#pragma warning(disable: 4244)
		ostr << std::clamp<int>(c.R * 255.999, 0, 255) << ' '
			<< std::clamp<int>(c.G * 255.999, 0, 255) << ' '
			<< std::clamp<int>(c.B * 255.999, 0, 255) << "\r\n";
#pragma warning(pop)
	};

	return ostr;
}