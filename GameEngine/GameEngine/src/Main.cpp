#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "EntityManager.h"
#include "Player.h"
#include "WorldObject.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

GLFWwindow* window;
EntityManager manager;

void init();
void update();

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

void init()
{
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_RELEASE) return;
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
