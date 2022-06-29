#pragma once
#include <iostream>
#include <memory>

class Entity;

class Component
{
public:
	std::shared_ptr<Entity> entity;

	Component()
	{
		entity = nullptr;
		std::cout << "Component created" << std::endl;
	}

	virtual ~Component() = default;

	virtual void init() = 0;
};
