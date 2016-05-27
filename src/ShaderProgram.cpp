//
// Created by Darren Mothersele on 05/05/2016.
//

#include "ShaderProgram.h"
#include <glm/gtc/type_ptr.hpp>


ShaderProgram::ShaderProgram() {
    shaderProgram = glCreateProgram();
}

int ShaderProgram::link() {
    glLinkProgram(shaderProgram);
    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (success)
    {
        projectionMatrixLocation = glGetUniformLocation(shaderProgram, "vp");
//        lightPosLocation = glGetUniformLocation(shaderProgram, "lightPosition");
        modelMatrixLocation = glGetUniformLocation(shaderProgram, "model");
    }
    return success;
}

void ShaderProgram::addShader(Shader shader) {
    glAttachShader(shaderProgram, shader.getShader());
}

void ShaderProgram::use() {
    glUseProgram(shaderProgram);
}

//void ShaderProgram::setLightPosition(glm::vec3 position)
//{
//    glUniform3f(lightPosLocation, position.x, position.y, position.z);
//}

void ShaderProgram::setProjectionMatrix(nature::Matrix matrix)
{
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setModelMatrix(nature::Matrix matrix)
{
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(matrix));
}





