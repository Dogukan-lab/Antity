#include "Player.h"

#include "Mesh.h"
#include "Transform.h"

Player::Player(const std::string& name)
{
	this->name = name; 
	this->addComponent<Mesh>();
	this->addComponent<Transform>(100.0f, 100.0f);
}

Player::~Player()
{
	std::cout << "Player destructed: " << this->name << std::endl;
}
