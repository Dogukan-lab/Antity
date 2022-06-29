#pragma once
#include "Component.h"

class Mesh : public Component //Liefst geen logica (updates draws),
								//helper functies mag wel
{
public:
	Mesh() = default;
	~Mesh() override = default;

	void init() override
	{
		std::cout << "Bruh momment mesh i guess" << std::endl;
		//Make VBO
	}
};
