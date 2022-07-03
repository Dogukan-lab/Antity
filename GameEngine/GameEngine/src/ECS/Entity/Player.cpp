#include "Player.h"
#include "Mesh.h"
#include "Transform.h"
#include "tigl.h"
#include "Camera.h"
#include "../../handler/Application.h"
#include "../../handler/InputHandler.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

using tigl::Vertex;
/**
* TODO: Add movement to player
* Do this with a singleton movement handler that you can get the callbacks from
* MAYBE: Scene singleton to get the glfw window for closing the apk.
*/
Player::Player()
{
	this->addComponent<Transform>();
	this->addComponent<Camera>();

	glfwSetInputMode(Application::getInstance()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	if (glfwRawMouseMotionSupported())
		glfwSetInputMode(Application::getInstance()->getWindow(), GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
}

Player::~Player()
{
}

void Player::move(float angle, float fac)
{
	auto& transform = this->getComponent<Transform>();

	transform.getPosition().x += (float)cos(transform.getRotation().y + glm::radians(angle)) * fac;
	transform.getPosition().z += (float)sin(transform.getRotation().y + glm::radians(angle)) * fac;
}

void Player::checkInput(float deltaTime)
{
	auto& transform = this->getComponent<Transform>();
	auto* window = Application::getInstance()->getWindow();

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		move(0, deltaTime * 2);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		move(180, deltaTime * 2);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		move(90, deltaTime * 2);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		move(-90, deltaTime * 2);
}

void Player::update()
{
	const double currentTime = glfwGetTime();
	static double lastFrameTime = 0;
	const double deltaTime = (currentTime - lastFrameTime);
	lastFrameTime = currentTime;

	auto& transform = this->getComponent<Transform>();

	double x, y;
	glfwGetCursorPos(Application::getInstance()->getWindow(), &x, &y);

	static double lastX = x;
	static double lastY = y;

	transform.getRotation().x -= (float)(lastY - y) / 100.0f;
	transform.getRotation().y -= (float)(lastX - x) / 100.0f;

	lastX = x;
	lastY = y;

	checkInput(deltaTime);
}

void Player::draw()
{
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	auto& transform = this->getComponent<Transform>();
	auto& camera = this->getComponent<Camera>();

	tigl::shader->setProjectionMatrix(camera.getProjectionMatrix(
		(float)(viewport[2] / viewport[3])
	));

	tigl::shader->setViewMatrix(camera.getLookAt(transform.getPosition(), transform.getRotation()));
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);
}

