#include "tigl.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Renderer.h"

using tigl::Vertex;

Renderer::Renderer()
{
	//set the list based on the entity manager list of entities
	//this->entities = EntityManager::getEntities();
    init();
}

void Renderer::init()
{
	//Basic tigl inits 
	tigl::shader->enableColor(true);
}


void Renderer::draw()
{
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);


    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 50.0f);

    tigl::shader->setProjectionMatrix(projection);

	/*tigl::shader->setProjectionMatrix(camera.getProjectionMatrix(
		(float)(viewport[2] / viewport[3])
	));*/
	tigl::shader->setViewMatrix(glm::lookAt(
		glm::vec3(1, 0, 0),
        glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	));

	tigl::shader->setModelMatrix(glm::mat4(1.0f));

	//Render alle andere entities

	/*set_model(glm::vec3(3, -1, 1), 1.0f, glm::vec3(0,0,0));
	render_cube();*/
}


