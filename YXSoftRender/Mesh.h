#pragma once

#include<vector>
#include<Eigen/Eigen>


class Mesh 
{
public:
	std::vector<Eigen::Vector3f> vertices;
	std::vector<Eigen::Vector3f> normals;
	std::vector<Eigen::Vector2f> texCoords;
	std::vector<int> indices;
};