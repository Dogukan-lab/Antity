#pragma once

#include "Entity.h"
#include "glm/glm.hpp"

class WorldObject : public Entity
{
public:
	WorldObject() = default;
	WorldObject(const std::string& fileName);
	~WorldObject() = default;


	void update() override;
	void draw() override;
};