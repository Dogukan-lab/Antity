#include "Model.h"
#include <fstream>
#include <sstream>
#include <iostream>

Model::Model(const std::string& fileName)
{
	std::ifstream fileReader(fileName);

	if (!fileReader.is_open())
	{
		std::cerr << "Could not open file " << fileName << std::endl;
		return;
	}

	std::string line;
	while (!fileReader.eof())
	{
		std::getline(fileReader, line);
		std::stringstream lineReader(line);

		std::string firstPart;
		lineReader >> firstPart;

		if (firstPart == "v")
		{
			glm::vec3 position(0, 0, 0);
			lineReader >> position.x;
			lineReader >> position.y;
			lineReader >> position.z;
			this->positions.push_back(position);
		}
		if (firstPart == "vt")
		{
			glm::vec3 normal(0, 0, 0);
			lineReader >> normal.x;
			lineReader >> normal.y;
			lineReader >> normal.z;
			this->normals.push_back(normal);
		}
		if (firstPart == "f")
		{
			Face face{};
			for (int i = 0; i < 3; i++)
			{
				char junk; //To temporarily store the "/"
				lineReader >> face.pos[i];
				lineReader >> junk;
				lineReader >> face.normal[i];
				lineReader >> junk;
				lineReader >> face.normal[i];
				face.pos[i]--;
				face.normal[i]--;
			}
			this->faces.push_back(face);
		}
	}
	loadVertices();
}

void Model::loadVertices()
{
	this->vertices.clear();
	for (const auto& face : this->faces)
	{
		for (int i = 0; i < 3; i++)
		{
			auto& vertexPosition = this->positions[face.pos[i]];
			auto& normalPosition = this->normals[face.normal[i]];

			this->vertices.push_back(tigl::Vertex::PCN(
				vertexPosition,
				{ 100,100,100,100 },
				normalPosition));
		}
	}
}

std::vector<tigl::Vertex>& Model::getVertices()
{
	return this->vertices;
}
