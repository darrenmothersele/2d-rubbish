//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef NATURE_SHADER_H
#define NATURE_SHADER_H

#include "nature.h"

class Shader {
    GLuint shader;

public:
    Shader(GLenum type, const char* path);
    ~Shader();

    GLuint getShader();

    void printLog()
    {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        cout << infoLog << endl;
    }

};


#endif //NATURE_SHADER_H
