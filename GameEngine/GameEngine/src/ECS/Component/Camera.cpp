#include "Camera.h"
#include "tigl.h"

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

void Camera::init()
{
}
