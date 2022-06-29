#pragma once
#include <string>

#include "Component.h"

class Transform : public Component
{
public:

	Transform(const float& posx, const float& posy) : posX(posx), posY(posy) {}

	~Transform() override = default;

	std::string toString()
	{
		return std::to_string(this->posX) + " " + std::to_string(this->posY);
	}


	inline void init() override
	{
		std::cout << toString() << std::endl;
	}

private:
	float posX;
	float posY;
};
