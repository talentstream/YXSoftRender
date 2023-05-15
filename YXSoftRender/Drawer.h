#pragma once

#include<Eigen/Eigen>
#include"Color.h"
#include"Buffer.h"

class Drawer
{
public:
	static void DrawPixel(const Eigen::Vector2f& point, Color color, Buffer<Color>& buffer);
	static void DrawLine(Eigen::Vector2f begin,Eigen::Vector2f end,Color color,Buffer<Color>& buffer);
	static void DrawTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2, Color color, Buffer<Color>& buffer);
	
};