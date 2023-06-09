#include "Renderer.h"

void Renderer::LoadMeshes(const std::string model_path)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, model_path.c_str())) {
		throw std::runtime_error(warn + err);
	}

	for (const auto& shape : shapes)
	{
		Mesh mesh{};
		for (const auto& index : shape.mesh.indices)
		{
			Eigen::Vector3f vertex;
			vertex.x() = attrib.vertices[3 * index.vertex_index + 0];
			vertex.y() = attrib.vertices[3 * index.vertex_index + 1];
			vertex.z() = attrib.vertices[3 * index.vertex_index + 2];
			mesh.vertices.emplace_back(vertex);

			Eigen::Vector3f normal;
			normal.x() = attrib.normals[3 * index.normal_index + 0];
			normal.y() = attrib.normals[3 * index.normal_index + 1];
			normal.z() = attrib.normals[3 * index.normal_index + 2];
			mesh.normals.emplace_back(normal);

			Eigen::Vector2f texCoord;
			texCoord.x() = attrib.texcoords[2 * index.texcoord_index + 0];
			texCoord.y() = attrib.texcoords[2 * index.texcoord_index + 1];
			mesh.texCoords.emplace_back(texCoord);

			mesh.indices.push_back(mesh.indices.size());
		}
		meshes.emplace_back(mesh);
	}
}	

void Renderer::Render()
{
	// TestDrawLine
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 200), Color(1, 1, 0, 1), *buffer);
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(100, 200), Color(0, 1, 0, 1), *buffer);
	Drawer::DrawLine(Eigen::Vector2f(100, 100), Eigen::Vector2f(200, 100), Color(0, 0, 1, 1), *buffer);
	// TestDrawTriangle
	Drawer::DrawTriangle(Eigen::Vector3f(0, 0, 1), Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(0, 100, 1), Color(1, 0, 0, 1), *buffer);
	Drawer::DrawTriangle(Eigen::Vector3f(100, 100, 1), Eigen::Vector3f(200, 100, 1), Eigen::Vector3f(200, 200, 1), Color(1, 0, 1, 1), *buffer);
	Drawer::DrawTriangle(Eigen::Vector3f(800, 450, 1), Eigen::Vector3f(450, 230, 1), Eigen::Vector3f(330, 200, 1), Color(0, 1, 0, 1), *buffer);

	for (int x = 0;x<configuration.resolution.width; ++x)
	{
		for (int y = 0; y < configuration.resolution.height; ++y)
		{
			Color color = buffer->GetData(x, y);
			configuration.canvas.setPixelColor(x, y, QColor(color.r * color.a * 255, color.g * color.a * 255, color.b * color.a * 255));
		}
	}
}

void Renderer::Display()
{
	configuration.label->setPixmap(QPixmap::fromImage(configuration.canvas));
}

Renderer::Renderer()
{
	buffer = new Buffer<Color>(configuration.resolution.width, configuration.resolution.height);
}
