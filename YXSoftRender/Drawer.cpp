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

float Barycentric2DFunction(Eigen::Vector3f begin, Eigen::Vector3f end, Eigen::Vector3f parameter)
{
	//fab(x,y) = (ya - yb)x + (xb - xa)y + xa * yb - xb * ya;
	float xa = begin.x(), ya = begin.y();
	float xb = end.x(), yb = end.y();
	float x = parameter.x(), y = parameter.y();
	return (ya - yb) * x + (xb - xa) * y + xa * yb - xb * ya;

}

void Drawer::DrawPixel(const Eigen::Vector2f& point, Color color, Buffer<Color>& buffer)
{
	int x = point.x(), y = point.y();
	buffer.SetData(color, x, y);
}

void Drawer::DrawLine(Eigen::Vector2f begin, Eigen::Vector2f end, Color color, Buffer<Color>& buffer)
{
	int x0 = begin.x(), y0 = begin.y();
	int x1 = end.x(), y1 = end.y();

	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;

	int err = (dx > dy ? dx : -dy) / 2;

	while (x0 != x1 || y0 != y1)
	{
		DrawPixel(Eigen::Vector2f(x0, y0), color, buffer);
		int e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void Drawer::DrawTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2, Color color, Buffer<Color>& buffer)
{
	int min_x = std::min(v0.x(), std::min(v1.x(), v2.x()));
	int max_x = std::max(v0.x(), std::max(v1.x(), v2.x()));
	int min_y = std::min(v0.y(), std::min(v1.y(), v2.y()));
	int max_y = std::max(v0.y(), std::max(v1.y(), v2.y()));

	for (int x = min_x; x <= max_x; x++)
	{
		for (int y = min_y; y <= max_y; y++)
		{
			// if (!InsideTriangle(x, y, v0, v1, v2)) continue;
			Eigen::Vector3f v(x, y, 1.0f);
			float alpha = Barycentric2DFunction(v1, v2, v) / Barycentric2DFunction(v1, v2, v0);
			float beta = Barycentric2DFunction(v2, v0, v) / Barycentric2DFunction(v2, v0, v1);
			float gamma = Barycentric2DFunction(v0, v1, v) / Barycentric2DFunction(v0, v1, v2);
			if (!(alpha > 0 && beta > 0 && gamma > 0)) continue;

			DrawPixel(Eigen::Vector2f(x, y), color, buffer);
		}
	}
}



