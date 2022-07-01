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
    this->addComponent<Transform>(glm::vec3{10, 10, 0}, glm::vec3{0, 0, -1});
	this->addComponent<Camera>(120.0f);
}

Player::~Player()
{
}

void Player::setModel(glm::vec3 pos, float scale, const glm::vec3& rotation)
{
    glm::mat4 model(1.0f);
    model = glm::translate(model, pos);
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    model = glm::scale(model, glm::vec3(scale * 0.5f, scale * 0.5f, scale * 0.5f));
    tigl::shader->setModelMatrix(model);
}

void Player::update()
{
	auto& transform = this->getComponent<Transform>();
}

void Player::draw()
{
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	auto& transform = this->getComponent<Transform>();
	auto& camera = this->getComponent<Camera>();

	tigl::shader->setProjectionMatrix(camera.getProjectionMatrix(
		(float)(viewport[2] / viewport[3])
	));

	tigl::shader->setViewMatrix(glm::lookAt(
		transform.getPosition(),
		transform.getRotation(),
		glm::vec3(0, 1, 0)));

    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);


    glEnable(GL_DEPTH_TEST);

    tigl::begin(GL_TRIANGLES);
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(-2, -1, -4), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(2, -1, -4), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(0, 1, -4), glm::vec4(0, 0, 1, 1)));


    tigl::addVertex(tigl::Vertex::PC(glm::vec3(-10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(-10, -1, 10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(10, -1, 10), glm::vec4(1, 1, 1, 1)));

    tigl::addVertex(tigl::Vertex::PC(glm::vec3(-10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(tigl::Vertex::PC(glm::vec3(10, -1, 10), glm::vec4(1, 1, 1, 1)));

    tigl::end();
}

