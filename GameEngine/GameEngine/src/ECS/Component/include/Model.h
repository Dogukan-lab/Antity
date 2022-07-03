#pragma once
#include <string>
#include <vector>
#include "tigl.h"

class Model
{
public:
	Model(const std::string& fileName);
	~Model() = default;

	void loadVertices();
	std::vector<tigl::Vertex>& getVertices();

private:
	std::vector<tigl::Vertex> vertices;

	struct Face
	{
		int pos[3];
		int normal[3];
	};

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<Face> faces;
};