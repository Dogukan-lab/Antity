#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "EntityManager.h"
#include "Player.h"
#include "shader/tigl.h"
using tigl::Vertex;

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

GLFWwindow* window;
EntityManager manager;

bool is_wireframed = false;
float input_angle = 0.0f;
float angle = 0.0f;
float lastTime = 0.0f;
float delta_time = 0.0f;
glm::vec3 cube_rotation = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 pos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

void init();
void update();
void draw();
//void set_model(glm::vec3 pos, float scale, const glm::vec3& rotation);
//void render_cube();

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
        draw();

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
}

//void check_keyboard_input()
//{
//    if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS)
//    {
//        is_wireframed = !is_wireframed;
//    }
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//    {
//        //Move forward
//        pos += delta_time * cameraFront;
//    }
//    if (glfwGetKey(window, GLFW_KEY_A))
//    {
//        //Move left
//        pos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * delta_time;
//    }
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//    {
//        //Move back
//        pos -= delta_time * cameraFront;
//    }
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//    {
//        //Move right
//        pos += glm::normalize(glm::cross(cameraFront, cameraUp)) * delta_time;
//    }
//    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//    {
//        cube_rotation.z++;
//    }
//    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//    {
//        cube_rotation.z--;
//    }
//    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//    {
//        cube_rotation.y--;
//    }
//    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//    {
//        cube_rotation.y++;
//    }
//}

void update()
{
    float time = glfwGetTime();
    delta_time = time - lastTime;
    lastTime = time;

    angle += delta_time * 100;

    manager.update();
}

//void set_model(glm::vec3 pos, float scale, const glm::vec3& rotation)
//{
//    glm::mat4 model(1.0f);
//    model = glm::translate(model, pos);
//    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
//    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
//    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
//    model = glm::scale(model, glm::vec3(scale * 0.5f, scale * 0.5f, scale * 0.5f));
//    tigl::shader->setModelMatrix(model);
//}

//van -0.5f naar 0.5f
//void render_cube()
//{
//    tigl::begin(GL_QUADS);
//    /* Back side */
//    tigl::addVertex(Vertex::P(glm::vec3(-0.5f, 0.5f, -0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(-0.5f, -0.5f, -0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(0.5f, -0.5f, -0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(0.5f, 0.5f, -0.5f)));
//
//    /* Right side of cube */
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 0.8f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.3f, 0.8f)));
//
//    /* Left side of cube */
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//
//    /* Top of cube */
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//
//    /* Bottom of cube */
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//    tigl::addVertex(Vertex::PC(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec4(0.5f, 0.3f, 0.1f, 1.0f)));
//
//    /* Face of cube */
//    tigl::addVertex(Vertex::P(glm::vec3(-0.5f, 0.5f, 0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(-0.5f, -0.5f, 0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(0.5f, -0.5f, 0.5f)));
//    tigl::addVertex(Vertex::P(glm::vec3(0.5f, 0.5f, 0.5f)));
//
//    tigl::end();
//}
//

void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    manager.draw();


    //set_model(glm::vec3(3, -1, 1), 1.0f, cube_rotation);
    //render_cube();

    //set_model(glm::vec3(-2, -1, 1), 1.0f, glm::vec3(10, 0, 0));
    //render_cube();

    //set_model(glm::vec3(-4, -1, 1), 1.0f, glm::vec3(0, 50, 0));
    //render_cube();

    //set_model(glm::vec3(-4, -1, -2), 1.0f, glm::vec3(0, 0, -100));
    //render_cube();
}