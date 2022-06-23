#pragma once

#include "Component.h"
#include <vector>
#include <memory>

class Entity
{
public:

	Entity();

	virtual ~Entity() {};

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	template <class T>
	std::shared_ptr<T> getComponent()
	{
		for (const auto& component : components)
		{
			auto& derived = dynamic_cast<T&>(component);
			if (derived) return derived;
		}
	}


private:
	bool isActive = true;
	std::vector<std::shared_ptr<Component>> components;
};