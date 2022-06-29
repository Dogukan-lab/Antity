#include "Player.h"

#include "Mesh.h"
#include "Transform.h"

Player::Player(const std::string& name)
{
	this->name = name; 
	this->addComponent<Mesh>();
	this->addComponent<Transform>(glm::vec3 {0,0,0}, 
								  glm::vec3{0,0,0}, 
								  glm::vec3{0,1,0});
}

Player::~Player()
{
	std::cout << "Player destructed: " << this->name << std::endl;
}

void Player::update()
{
	auto& transform = this->getComponent<Transform>();

	transform.getPosition().x += 1.0f;
	transform.toString();
}

