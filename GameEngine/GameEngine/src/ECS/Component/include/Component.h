#pragma once
#include <memory>
#include "Entity.h"

class Component
{
public:
	virtual void get_component_id() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
private:
	std::weak_ptr<Entity> entity;


	
};