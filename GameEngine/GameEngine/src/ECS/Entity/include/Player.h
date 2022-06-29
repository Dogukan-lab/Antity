#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	//health comp,transform comp
	//Zeker weten dat de entity de benodigde components heeft

	Player(const std::string& name);

	~Player() override;

	inline void update() override
	{
		//Mesh naar renderer
	}

private:
	std::string name;
};
