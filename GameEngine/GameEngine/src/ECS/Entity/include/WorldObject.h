#pragma once

#include "Entity.h"

class WorldObject : public Entity
{
public:
	WorldObject();
	WorldObject(const std::string& fileName);
	~WorldObject() = default;


	void update() override;
	void draw() override;
};