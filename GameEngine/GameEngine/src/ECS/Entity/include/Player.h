#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	//health comp,transform comp
	//Zeker weten dat de entity de benodigde components heeft

	Player(const std::string& name);

	~Player() override;

	void update() override;

private:
	std::string name;
};
