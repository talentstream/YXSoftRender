#include "Renderer.h"

void TestDrawLine(Buffer<Color>& buffer)
{
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 200), Color(1, 1, 0, 1), buffer);
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(100, 200), Color(0, 1, 0, 1), buffer);
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 100), Color(0, 0, 1, 1), buffer);
}

void TestDrawTriangle(Buffer<Color>& buffer)
{
	Drawer::DrawTriangle(Eigen::Vector3f(0, 0, 1), Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(0, 100, 1), Color(1, 0, 0, 1), buffer);
	Drawer::DrawTriangle(Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(200, 100, 1), Eigen::Vector3f(200, 200, 1), Color(1, 0, 1, 1), buffer);
	Drawer::DrawTriangle(Eigen::Vector3f(800, 450, 1), Eigen::Vector3f(450, 230, 1), Eigen::Vector3f(330, 200, 1), Color(0, 1, 0, 1), buffer);
}


void Renderer::Render()
{
	Buffer<Color> buffer(configuration.resolution.width, configuration.resolution.height);

	TestDrawLine(buffer);
	TestDrawTriangle(buffer);


	for (int x = 0;x<configuration.resolution.width; ++x)
	{
		for (int y = 0; y < configuration.resolution.height; ++y)
		{
			Color color = buffer.GetData(x, y);
			configuration.canvas.setPixelColor(x, y, QColor(color.r * color.a * 255, color.g * color.a * 255, color.b * color.a * 255));
		}
	}
}

void Renderer::Display()
{
	configuration.label->setPixmap(QPixmap::fromImage(configuration.canvas));
}