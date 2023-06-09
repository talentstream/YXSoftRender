#pragma once

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

#include<vector>

#include<qimage.h>
#include<qlabel.h>
#include"Configuration.h"
#include"Drawer.h"
#include"Color.h"
#include"Buffer.h"
#include"Mesh.h"



class Renderer
{
public:
	void LoadMeshes(const std::string model_path);
	void Render();
	void Display();
	Renderer();
	Buffer<Color>* buffer;
private:
	std::vector<Mesh> meshes;
};
