#pragma once

#include "Entity.h"

class WorldObject : public Entity
{
public:
	WorldObject();
	~WorldObject() = default;


	void update() override;
	void draw() override;
};