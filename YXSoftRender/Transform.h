#pragma once
#include<Eigen/Eigen>

class Transform
{
public:
	Eigen::Matrix4f SetViewMatrix(Eigen::Vector3f eye_pos);
	Eigen::Matrix4f SetProjectionMatrix(float eye_fov, float aspect_ratio, float zNear, float zFar);
	Eigen::Matrix4f SetModelMatrix(Eigen::Vector3f translation,float rotation_angle,Eigen::Vector3f scale);
private:
	Eigen::Matrix4f GetViewMatrix();
};