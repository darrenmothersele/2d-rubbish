//
// Created by Darren Mothersele on 05/05/2016.
//

#include <cstdlib>
#include "AppRunner.h"
#include "nature.h"
#include "Window.h"
#include "ShaderProgram.h"

int AppRunner::operator()() {

    if (!glfwInit())
        throw "Failed to initialize GLFW";

    Window::getWindow().setClearColor({0.f, 0.f, 0.f, 1.f});
    Window::getWindow().clear();

    ShaderProgram shader;
    {
        Shader vertexShader(GL_VERTEX_SHADER, "shaders/2d.v.glsl");
        Shader fragmentShader(GL_FRAGMENT_SHADER, "shaders/2d.f.glsl");
        shader.addShader(vertexShader);
        shader.addShader(fragmentShader);
        if (!shader.link())
        {
            shader.printLog();
            throw "Error linking Shader";
        }
    }

    setup();

    while (!Window::getWindow().shouldClose())
    {
        shader.use();
        shader.setProjectionMatrix(projection);
        shader.setModelMatrix(glm::mat4{});

        draw();

        Window::getWindow().update();
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}


