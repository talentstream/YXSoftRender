#include "Renderer.h"

void Renderer::Render()
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

void Renderer::Display()
{
	configuration.label->setPixmap(QPixmap::fromImage(configuration.canvas));
}