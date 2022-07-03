#include "Mesh.h"

Mesh::Mesh(std::shared_ptr<Model> model)
{
	this->model = model;
}

std::shared_ptr<Model> Mesh::getModel()
{
	return this->model;
}
