#pragma once
#include <array>
#include <bitset>
#include <memory>

/**
 * @brief Utilities for getting ID's and certain constexprs
 */

class Entity;
class Component;

namespace util
{
	/*using EntityID = uint32_t;
	using ComponentID = uint32_t;*/
	using EntityID = size_t;
	using ComponentID = size_t;

	inline EntityID getUniqueEntityID()
	{
		static EntityID lastID = 0u;
		return lastID++;
	}

	inline ComponentID getUniqueComponentID()
	{
		static ComponentID lastID = 0u;
		return lastID++;
	}

	template <typename T> ComponentID getComponentTypeID() noexcept
	{
		static_assert(std::is_base_of<Component, T>::value, "Provided component is not a derivative of the base!");
		static const ComponentID typeID = getUniqueComponentID();
		return typeID;
	}

	constexpr size_t MAX_ENTITIES = 10;
	constexpr size_t MAX_COMPONENTS = 32;

	using ComponentBitSet = std::bitset<MAX_COMPONENTS>;
	using ComponentList = std::array<std::shared_ptr<Component>, MAX_COMPONENTS>;
}
