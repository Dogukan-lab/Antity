#pragma once

#include "Component.h"
#include <vector>
#include <memory>
#include <bitset>

class Entity
{
public:

	Entity();

	virtual ~Entity() {}

private:

	const unsigned int entity_id;
	//std::bitset<> //Om components met elkaar te vergelijken 
};