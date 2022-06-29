#pragma once
#include <vector>
#include "Entity.h"

class EntityManager
{
public:
	std::vector<std::shared_ptr<Entity>> entities;

	//void makeEntities()
	//{
	//	for (int i = 0; i < util::MAX_ENTITIES; i++)
	//	{
	//		auto ptr = std::make_unique<Entity>();
	//		this->entities.push_back(std::move(ptr));
	//	}
	//}

	/**
	 * Sets the list of entities up with w/a standard size 
	 */
	inline EntityManager()
	{
		entities.reserve(util::MAX_ENTITIES);
	}

	~EntityManager()
	{
		this->entities.clear();
	}

	/**
	 * @brief generic add function for adding entities to the manager
	 */
	template <typename T>
	std::shared_ptr<T> addEntity()
	{
		static_assert(std::is_base_of<Entity, T>::value, "Provided entity is not derivative of Entity!");
		auto ptr = std::make_shared<T>();
		this->entities.push_back(ptr);
		return ptr;
	}

	/**
	 * @see original @addEntity()	
	 * Overloaded function to pass args as well
	 */
	template <typename T, typename... TArgs>
	std::shared_ptr<T> addEntity(TArgs&&... args)
	{
		static_assert(std::is_base_of<Entity, T>::value, "Provided entity is not derivative of Entity!");
		auto ptr = std::make_shared<T>(std::forward<TArgs>(args)...);
		this->entities.push_back(ptr);
		return ptr;
	}


	/**
	 * TODO Make this function pass an @Entity id instead
	 */

	std::unique_ptr<Entity> destroyEntity(const std::shared_ptr<Entity>& entity)
	{
		//static_assert(std::is_base_of<Entity, T>::value && "Provided entity is not derivative of Entity!");
		const auto ref = std::find(this->entities.begin(),
			this->entities.end(),
			entity);

		if(ref != this->entities.end())
		{
			this->entities.erase(ref);
		}

		return nullptr;
	}

	std::vector<std::shared_ptr<Entity>>& getEntities()
	{
		return this->entities;
	}

	std::shared_ptr<Entity> getEntity(const std::shared_ptr<Entity>& entity) const
	{
		const auto ref=  std::find(
			this->entities.begin(),
			this->entities.end(),
			entity
		);

		if(ref != this->entities.end())
		{
			return *ref;
		}

		return nullptr;
	}

	void update() const
	{
		for(const auto& entity : this->entities)
		{
			entity->update();
		}
	}
};
