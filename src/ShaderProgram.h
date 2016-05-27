//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef NATURE_SHADERPROGRAM_H
#define NATURE_SHADERPROGRAM_H

#include "nature.h"
#include "Shader.h"

class ShaderProgram {
    GLuint shaderProgram;
//    GLint lightPosLocation;
    GLint projectionMatrixLocation;
    GLint modelMatrixLocation;

public:
    ShaderProgram();
    int link();

    void addShader(Shader shader);
    void printLog()
    {
        GLchar infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    void use();

    GLuint getShader() { return shaderProgram; }

    //void setLightPosition(glm::vec3 position);

    void setProjectionMatrix(nature::Matrix matrix);
    void setModelMatrix(nature::Matrix matrix);

};



#endif //NATURE_SHADERPROGRAM_H
