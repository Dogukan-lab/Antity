#pragma once
#include "Entity.h"
#include "tigl.h"

class Player : public Entity
{
public:
	//health comp,transform comp
	//Zeker weten dat de entity de benodigde components heeft

	Player();
	~Player() override;

	void checkInput(float deltaTime);
	void move(float angle, float fac);

	void update() override;
	void draw() override;

private:
};
