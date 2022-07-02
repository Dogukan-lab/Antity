#include "Player.h"
#include "Mesh.h"
#include "Transform.h"
#include "tigl.h"
#include "Camera.h"

using tigl::Vertex;
/**
* TODO: Add movement to player
* Do this with a singleton movement handler that you can get the callbacks from
* MAYBE: Scene singleton to get the glfw window for closing the apk.
*/
Player::Player()
{
	this->addComponent<Mesh>();
    this->addComponent<Transform>();
	this->addComponent<Camera>();
}

Player::~Player()
{
}


void Player::update()
{
	auto& transform = this->getComponent<Transform>();
	transform.getPosition().z += 1 * 0.1;
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

