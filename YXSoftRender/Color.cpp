#include "Color.h"
#include<algorithm>

Color::Color(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

const Color Color::Red = Color(1, 0, 0, 1);
const Color Color::Green = Color(0, 1, 0, 1);
const Color Color::Blue = Color(0, 0, 1, 1);
const Color Color::Black = Color(0, 0, 0, 1);
const Color Color::White = Color(1, 1, 1, 1);

Color Color::operator+(const Color& c)
{
    return Color(std::clamp(c.r + this->r,float(0),float(1)),
        std::clamp(c.g + this->g, float(0), float(1)),
        std::clamp(c.b + this->b, float(0), float(1)),
        std::clamp(c.a + this->a, float(0), float(1)));
}

Color Color::operator-(const Color& c)
{
    return Color(std::clamp(-c.r + this->r, float(0), float(1)),
        std::clamp(-c.g + this->g, float(0), float(1)),
        std::clamp(-c.b + this->b, float(0), float(1)),
        std::clamp(-c.a + this->a, float(0), float(1)));
}

Color Color::operator/(const float& s)
{
    return Color(std::clamp(this->r / s, float(0), float(1)),
        std::clamp(this->g / s, float(0), float(1)),
        std::clamp(this->b / s, float(0), float(1)),
        std::clamp(this->a / s, float(0), float(1)));
}

Color Color::operator*(const float& s)
{
    return Color(std::clamp(this->r * s, float(0), float(1)),
        std::clamp(this->g * s, float(0), float(1)),
        std::clamp(this->b * s, float(0), float(1)),
        std::clamp(this->a * s, float(0), float(1)));
}

float& Color::operator[](const int& i)
{
    switch (i)
    {
    case 0:
        return r;
    case 1:
        return g;
    case 2:
        return b;
    case 3:
        return a;
    default:
        return r;
    }
}
