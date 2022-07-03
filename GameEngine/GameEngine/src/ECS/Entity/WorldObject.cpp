#include "WorldObject.h"
#include "tigl.h"
#include "Transform.h"
#include "Mesh.h"
#include "ObjectLoader.h"

WorldObject::WorldObject()
{
	this->addComponent<Transform>();
	this->addComponent<Mesh>(ObjectLoader::getModel("..\\GameEngine\\resources\\plane.obj"));
}

WorldObject::WorldObject(const std::string& fileName)
{
}

void WorldObject::update()
{
}

void WorldObject::draw()
{

	auto& transform = this->getComponent<Transform>();
    auto modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::scale(modelMatrix, transform.getScale());
    modelMatrix = glm::translate(modelMatrix, transform.getPosition());

    auto rotation = transform.getRotation();
    modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0, 0, 1));

	tigl::drawVertices(GL_QUADS, this->getComponent<Mesh>().getModel()->getVertices());
}
