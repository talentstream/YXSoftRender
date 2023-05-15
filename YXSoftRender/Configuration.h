#pragma once

#include<qimage.h>
#include<qlabel.h>

typedef struct DisplayResolution
{
	int width = 1600;
	int height = 900;
}Resolution;

class Configuration
{
public:
	Resolution resolution;
	QImage canvas;
	QLabel* label;
};

extern Configuration configuration;


