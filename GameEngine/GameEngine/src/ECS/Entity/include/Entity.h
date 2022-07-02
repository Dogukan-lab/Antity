#pragma once
#include "util.h"
#include "Component.h"


/**
 * @class Base class for every entity within the structure
 * Generic functions to add and remove @components from the entity
 */
class Entity
{
public:
	util::ComponentList components{};
	util::ComponentBitSet componentBitSet;

	Entity() = default;

	virtual ~Entity() = default;

	virtual void update() = 0; //Mesh submit naar een renderer bijvoorbeeld
	virtual void draw() {}
	virtual void init() {}

	template <typename T, typename... TArgs>
	inline std::shared_ptr<T> addComponent(TArgs&&... args)
	{
		auto ptr = std::make_shared<T>(std::forward<TArgs>(args)...);

		/*std::unique_ptr<Component> uPtr{ component };
		this->components.push_back(std::move(uPtr));*/

		this->componentBitSet[util::getComponentTypeID<T>()] = true;
		this->components[util::getComponentTypeID<T>()] = ptr;

		ptr->init();

		return ptr;
	}

	template <typename T>
	inline T& getComponent()
	{
		//Transform
		auto ptr = this->components[util::getComponentTypeID<T>()];
		return static_cast<T&>(*ptr.get());
	}

private:
	size_t entityID;
};
