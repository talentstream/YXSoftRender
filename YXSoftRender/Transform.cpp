#include "Transform.h"

Eigen::Matrix4f Transform::SetViewMatrix(Eigen::Vector3f eye_pos)
{
	Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f translate;
	translate <<
		1, 0, 0, -eye_pos[0],
		0, 1, 0, -eye_pos[1],
		0, 0, 1, -eye_pos[2],
		0, 0, 0, 1;

	view = translate * view;

	return view;
}

Eigen::Matrix4f Transform::SetProjectionMatrix(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
	Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

	float eye_angle = eye_fov * acos(-1) / 180;

	float top = tan(eye_angle / 2.0f) * zNear;
	float right = top * aspect_ratio;

	projection <<
		zNear / right, 0, 0, 0,
		0, zNear / top, 0, 0,
		0, 0, (zNear + zFar) / (zNear - zFar), (2 * zNear * zFar) / (zNear - zFar),
		0, 0, -1, 0;

	return projection;
}

Eigen::Matrix4f Transform::SetModelMatrix(Eigen::Vector3f translation, float rotation_angle, Eigen::Vector3f scale)
{
	float angle = rotation_angle * acos(-1) / 180.0f;
	Eigen::Matrix4f m_rotation;

	m_rotation <<
		cos(angle), 0, sin(angle), 0,
		0, 1, 0, 0,
		-sin(angle), 0, cos(angle), 0,
		0, 0, 0, 1;

	Eigen::Matrix4f m_scale;
	m_scale <<
		scale.x(), 0, 0, 0,
		0, scale.y(), 0, 0,
		0, 0, scale.z(), 0,
		0, 0, 0, 1;

	Eigen::Matrix4f m_translation;
	m_translation <<
		1, 0, 0, translation.x(),
		0, 1, 0, translation.y(),
		0, 0, 1, translation.z(),
		0, 0, 0, 1;

	return m_translation * m_rotation * m_scale;
}
