#include "Drawer.h"

void Drawer::DrawLine(Eigen::Vector2f begin, Eigen::Vector2f end,Eigen::Vector3f color)
{
	int x0 = begin.x(), y0 = begin.y();
	int x1 = end.x(), y1 = end.y();

	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;

	int err = (dx > dy ? dx : -dy) / 2;

	while (x0 != x1 || y0 != y1)
	{
		DrawPixel(Eigen::Vector2f(x0, y0), color);
		int e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void Drawer::DrawPixel(const Eigen::Vector2f& point, const Eigen::Vector3f& color)
{
	int x = point.x(), y = point.y();
	int r = color.x(), g = color.y(), b = color.z();
	QRgb qcolor = qRgb(r, g, b);
	configuration.canvas.setPixel(x, y, qcolor);
}
