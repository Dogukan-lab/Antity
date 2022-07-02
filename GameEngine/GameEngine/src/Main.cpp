#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "EntityManager.h"
#include "Player.h"
#include "handler/Application.h"
#include "handler/InputHandler.h"
#include "WorldObject.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

GLFWwindow* window;
Application* Application::instance = 0;
InputHandler* InputHandler::instance = 0;
EntityManager manager;

using tigl::Vertex;

void init();
void update();
void draw();

int main(void)
{

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        update();
        manager.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

//void keycallback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    InputHandler::getInstance()->setKeyCallbacks(key, action);
//}

void init()
{
    Application::getInstance()->setWindow(window);
    /*InputHandler::getInstance()->setKeyCallbacks(GLFW_KEY_W, GLFW_PRESS);
    InputHandler::getInstance()->setKeyCallbacks(GLFW_KEY_A, GLFW_PRESS);
    InputHandler::getInstance()->setKeyCallbacks(GLFW_KEY_S, GLFW_PRESS);
    InputHandler::getInstance()->setKeyCallbacks(GLFW_KEY_D, GLFW_PRESS);
    InputHandler::getInstance()->setKeyCallbacks(GLFW_KEY_ESCAPE, GLFW_PRESS);*/

    //glfwSetKeyCallback(window, keycallback);
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE)
                glfwSetWindowShouldClose(window, true);
        });
    
    glEnable(GL_DEPTH_TEST);
    tigl::shader->enableColor(true);



    manager.addEntity<Player>();
    manager.addEntity<WorldObject>();
}



void update()
{
    manager.update();
}


void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 50.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(glm::lookAt(
        glm::vec3(0,0,1),
        glm::vec3(0,0,0),
        glm::vec3(0,1,0)
       ));
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);

    glEnable(GL_DEPTH_TEST);

    tigl::begin(GL_TRIANGLES);
    tigl::addVertex(Vertex::PC(glm::vec3(-2, -1, -4), glm::vec4(1, 0, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(2, -1, -4), glm::vec4(0, 1, 0, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(0, 1, -4), glm::vec4(0, 0, 1, 1)));


    tigl::addVertex(Vertex::PC(glm::vec3(-10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(-10, -1, 10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(10, -1, 10), glm::vec4(1, 1, 1, 1)));

    tigl::addVertex(Vertex::PC(glm::vec3(-10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(10, -1, -10), glm::vec4(1, 1, 1, 1)));
    tigl::addVertex(Vertex::PC(glm::vec3(10, -1, 10), glm::vec4(1, 1, 1, 1)));

    tigl::end();
}