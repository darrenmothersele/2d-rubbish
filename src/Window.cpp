//
// Created by Darren Mothersele on 05/05/2016.
//

#include <GL/glew.h>
#include "Window.h"

int width;
int height;
glm::mat4 projection;

Window::Window(const int width, const int height)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, "Cecil", nullptr, nullptr);
    if (!window)
        throw "Failed to open window";
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        throw "Failed to initialize GLEW";

    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    glViewport(0, 0, screenWidth, screenHeight);
    projection = glm::ortho(0, screenWidth, screenHeight, 0);

    glfwSetWindowSizeCallback(window, resizeCallback);


    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwSwapBuffers(window);
}

void Window::setClearColor(nature::Color c)
{
    glClearColor(c.r, c.g, c.b, c.a);
}

void Window::setSize(int w, int h)
{
    width = w;
    height = h;
    glfwSetWindowSize(window, w, h);
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
}

void Window::clear(float c)
{
    glClearColor(c, c, c, 1.f);
    clear();
}

void Window::resizeCallback(GLFWwindow *window, int w, int h)
{
//    int screenWidth, screenHeight;
//    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    projection = glm::ortho(0, w, h, 0);
}










