#include "Transform.h"

Transform::Transform()
{
	this->position = glm::zero <glm::vec3>();
	this->rotation = glm::zero <glm::vec3>();
}

Transform::Transform(glm::vec3 newPosition, glm::vec3 newRotation) : position(newPosition),
	rotation(newRotation)
{
}

Transform::Transform(glm::vec3 newPosition, glm::vec3 newRotation, glm::vec3 newScale) :
position(newPosition), rotation(newRotation), scale(newScale)
{
}

void Transform::init()
{
	toString();
}


glm::vec3& Transform::getPosition() 
{
	return this->position;
}

glm::vec3 Transform::getRotation() 
{
	return this->rotation;
}

glm::vec3 Transform::getScale() 
{
	return this->scale;
}

void Transform::toString()
{
	std::cout << glm::to_string(this->getPosition()) << std::endl;
}