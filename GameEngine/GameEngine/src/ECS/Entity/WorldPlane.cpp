#include "WorldPlane.h"
#include "Transform.h"
#include "tigl.h"

WorldPlane::WorldPlane()
{
	this->addComponent<Transform>(glm::vec3{ 5, 0, 0 }, glm::vec3{0, 0, 0});
}

void WorldPlane::update()
{
}

void WorldPlane::draw()
{
    glEnable(GL_DEPTH_TEST);

    tigl::shader->enableColor(true);

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
