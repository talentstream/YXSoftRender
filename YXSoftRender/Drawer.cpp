#include "Drawer.h"

bool InsideTriangle(int x, int y, Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2)
{
	Eigen::Vector3f p(x, y, 1.0);
	Eigen::Vector3f f0 = v1.cross(v0);
	Eigen::Vector3f f1 = v2.cross(v1);
	Eigen::Vector3f f2 = v0.cross(v2);

	if ((p.dot(f0) * f0.dot(v2)) > 0 && (p.dot(f1) * f1.dot(v0)) > 0 && (p.dot(f2) * f2.dot(v1) > 0))
		return true;

	return false;
}

void Drawer::DrawPixel(const Eigen::Vector2f& point, const Eigen::Vector3f& color)
{
	int x = point.x(), y = point.y();
	int r = color.x(), g = color.y(), b = color.z();
	QRgb qcolor = qRgb(r, g, b);
	configuration.canvas.setPixel(x, y, qcolor);
}

void Drawer::DrawLine(Eigen::Vector2f begin, Eigen::Vector2f end, Eigen::Vector3f color)
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

void Drawer::DrawTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2, Eigen::Vector3f color)
{
	int min_x = std::min(v0.x(), std::min(v1.x(), v2.x()));
	int max_x = std::max(v0.x(), std::max(v1.x(), v2.x()));
	int min_y = std::min(v0.y(), std::min(v1.y(), v2.y()));
	int max_y = std::max(v0.y(), std::max(v1.y(), v2.y()));

	for (int x = min_x; x <= max_x; x++)
	{
		for (int y = min_y; y <= max_y; y++)
		{
			if (!InsideTriangle(x, y, v0, v1, v2)) continue;
			DrawPixel(Eigen::Vector2f(x, y), Eigen::Vector3f(0, 0, 0));
		}
	}
}



