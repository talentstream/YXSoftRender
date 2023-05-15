#pragma once

#include<Eigen/Eigen>
#include<qimage.h>
#include"Configuration.h"

class Drawer
{
public:
	static void DrawPixel(const Eigen::Vector2f& point, const Eigen::Vector3f& color);
	static void DrawLine(Eigen::Vector2f begin,Eigen::Vector2f end,Eigen::Vector3f color);
	static void DrawTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2, Eigen::Vector3f color);
	
};