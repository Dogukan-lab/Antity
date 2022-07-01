#pragma once
#include "Component.h"
#include <glm/gtc/matrix_transform.hpp>

class Camera : public Component
{
public:
	Camera();
	Camera(const float& newFov);
	Camera(const float& newFov, const float& newNear, const float& newFar);
	~Camera() = default;

	glm::mat4 getProjectionMatrix(float aspectRatio);

	void init() override;

private:
	float fov;
	float zNear;
	float zFar;
};