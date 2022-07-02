#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera()
{
	this->fov = 90.0f;
	this->zNear = 0.1f;
	this->zFar = 100.0f;
}

Camera::Camera(const float& newFov)
{
	this->fov = newFov;
	this->zNear = 0.1f;
	this->zFar = 100.0f;
}

Camera::Camera(const float& newFov, const float& newNear, const float& newFar)
{
	this->fov = newFov;
	this->zNear = newNear;
	this->zFar = newFar;
}

glm::mat4 Camera::getProjectionMatrix(float aspectRatio)
{
	return glm::perspective(glm::radians(this->fov),
		aspectRatio, this->zNear, this->zFar);
}

glm::mat4 Camera::getLookAt(glm::vec3& position, glm::vec3& rotation)
{
	glm::mat4 ret = glm::mat4(1.0f);
	ret = glm::rotate(ret, rotation.x, glm::vec3(1, 0, 0));
	ret = glm::rotate(ret, rotation.y, glm::vec3(0, 1, 0));
	ret = glm::translate(ret, position);

	return ret;
}

void Camera::init()
{
}
