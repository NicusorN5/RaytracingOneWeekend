#pragma once
#include "Color.hpp"
#include <memory>
#include <ostream>

class PPMImage
{
	unsigned width;
	unsigned height;
	std::unique_ptr<Color[]> image;
	std::unique_ptr<double[]> zbuffer;

	Color& at(unsigned x, unsigned y);
public:
	PPMImage(const unsigned _width, const unsigned _heigth);
	PPMImage(const PPMImage&) = delete;
	PPMImage(PPMImage&&) noexcept = default;

	bool write(unsigned x, unsigned y, double z, Color c);

	Color at(unsigned x, unsigned y) const;

	unsigned get_width() const;
	unsigned get_height() const;

	struct iterator
	{
		using iterator_category = std::contiguous_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = Color;
		using pointer = Color*;
		using reference = Color&;

	private:
		Color* ptr;
	public:
		iterator(Color* p_col);

		Color& operator*();

		Color* operator->();

		//++a
		iterator& operator ++();

		//a++
		iterator operator++(int);

		//-- a
		iterator& operator --();

		//a --
		iterator operator--(int);

		friend auto operator <=>(const iterator&, const iterator&) = default;
	};

	iterator begin();
	iterator end();

	iterator begin() const;
	iterator end() const;

	friend std::ostream& operator <<(std::ostream& ostr, const PPMImage& image);
};