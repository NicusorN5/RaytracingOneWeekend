#include "Color.hpp"

Color Color::operator+(const Color& c) const
{
    return 
    {
        R + c.R,
        G + c.G,
        B + c.B,
        A + c.A 
    };
}

Color& Color::operator+=(const Color& c)
{
    R += c.R;
    G += c.G;
    B += c.B;
    A += c.A;
    return *this;
}

Color Color::operator*(const double s) const
{
    return 
    {
        R * s,
        G * s,
        B * s,
        A * s 
    };
}

Color Color::operator*(const Color& c) const
{
    return 
    {
        R * c.R,
        G * c.G,
        B * c.B,
        A * c.A 
    };
}

Color operator*(const double s, const Color& c)
{
    return 
    {
        c.R * s,
        c.G * s,
        c.B * s,
        c.A * s 
    };
}
