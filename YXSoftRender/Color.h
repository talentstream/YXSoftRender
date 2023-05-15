#pragma once
class Color
{
public:
	float r = 0, g = 0, b = 0, a = 0;
	Color() {}
	Color(float r, float g, float b, float a);

	const static Color Red;
	const static Color Green;
	const static Color Blue;
	const static Color Black;
	const static Color White;

	Color operator+(const Color& c);
	Color operator-(const Color& c);
	Color operator/ (const float& s);
	Color operator* (const float& s);
	float& operator[](const int& i);
};