#pragma once
#include "Entity.h"

class WorldPlane : public Entity
{
public:
	WorldPlane();
	/*WorldPlane(const std::string& fileName);*/ //Dont know if this is necessary for a plane
	~WorldPlane() = default;


	void update() override;
	void draw() override;

private:
};