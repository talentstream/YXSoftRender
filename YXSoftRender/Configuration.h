#pragma once

#include<qimage.h>
#include<qlabel.h>

typedef struct DisplayResolution
{
	int width = 800;
	int height = 450;
}Resolution;

class Configuration
{
public:
	Resolution resolution;
	QImage canvas;
	QLabel* label;
};

extern Configuration configuration;


