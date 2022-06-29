#pragma once
#include <string>
#include <glm/vec3.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Component.h"

/**
 * @brief Basic movement component to scale rotate and move an object/entity
 * within the environment.
 */
class Transform : public Component
{
public:
	Transform();
	Transform(glm::vec3 newPosition, glm::vec3 newRotation);
	Transform(glm::vec3 newPosition, glm::vec3 newRotation, glm::vec3 newScale);

	~Transform() override
	{
		std::cout << "Destructing Transform" << std::endl;
	};

	void init() override;

	void toString();

	glm::vec3& getPosition();

	glm::vec3 getRotation();

	glm::vec3 getScale();

private:
	glm::vec3 position{};
	glm::vec3 rotation{};
	glm::vec3 scale {.5f, .5f, .5f};
}; 
