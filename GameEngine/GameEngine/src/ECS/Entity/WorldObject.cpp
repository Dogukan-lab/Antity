#include "WorldObject.h"
#include "tigl.h"
#include "Transform.h"
#include "Mesh.h"
#include "ObjectLoader.h"

WorldObject::WorldObject(const std::string& fileName)
{
    this->addComponent<Transform>(glm::vec3{10, 2, 3}, glm::vec3{0, 3, 1});
    this->addComponent<Mesh>(ObjectLoader::getModel(fileName));
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
