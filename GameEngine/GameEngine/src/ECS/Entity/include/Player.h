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

	void setModel(glm::vec3 pos, float scale, const glm::vec3& rotation);

	void update() override;
	void draw() override;

private:
};
