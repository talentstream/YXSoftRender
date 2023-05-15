#include "Renderer.h"

void TestDrawPixel()
{
	QRgb value;
	value = qRgb(0, 0, 0);
	configuration.canvas.setPixel(0, 1, value);
	configuration.canvas.setPixel(0, 2, value);
	configuration.canvas.setPixel(0, 3, value);
	configuration.canvas.setPixel(1, 1, value);
	configuration.canvas.setPixel(1, 2, value);
	configuration.canvas.setPixel(1, 3, value);
	configuration.canvas.setPixel(2, 1, value);
	configuration.canvas.setPixel(2, 2, value);
	configuration.canvas.setPixel(2, 3, value);
	configuration.canvas.setPixel(3, 1, value);
	configuration.canvas.setPixel(3, 2, value);
	configuration.canvas.setPixel(3, 3, value);
	for (int i = 0; i < 400; i++)
	{
		configuration.canvas.setPixel(i, 1, value);
		configuration.canvas.setPixel(i, 2, value);
		configuration.canvas.setPixel(i, 3, value);
	}
}

void TestDrawLine()
{
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 200), Eigen::Vector3f(255, 0, 0));
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(100, 200), Eigen::Vector3f(0, 255, 0));
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 100), Eigen::Vector3f(0, 0, 255));
}

void TestDrawTriangle()
{
	Drawer::DrawTriangle(Eigen::Vector3f(0, 0, 1), Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(0, 100, 1), Eigen::Vector3f(255, 0, 0));
	Drawer::DrawTriangle(Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(200, 100, 1), Eigen::Vector3f(200, 200, 1), Eigen::Vector3f(0, 255, 0));
	Drawer::DrawTriangle(Eigen::Vector3f(800, 450, 1), Eigen::Vector3f(450, 230, 1), Eigen::Vector3f(330, 200, 1), Eigen::Vector3f(0, 0, 255));
}
void Renderer::Render()
{
	TestDrawPixel();
	TestDrawLine();
	TestDrawTriangle();
}

void Renderer::Display()
{
	configuration.label->setPixmap(QPixmap::fromImage(configuration.canvas));
}