#pragma once
#include "Component.h"
#include "Model.h"

class Mesh : public Component //Liefst geen logica (updates draws),
								//helper functies mag wel
{
public:
	Mesh() = default;
	Mesh(std::shared_ptr<Model> model);
	~Mesh() override = default;

	void init() override
	{
		std::cout << "Bruh momment mesh i guess" << std::endl;
		//Make VBO
	}

	std::shared_ptr<Model> getModel();

private:
	std::shared_ptr<Model> model;
};
