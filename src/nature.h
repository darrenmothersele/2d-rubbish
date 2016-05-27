//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef NATURE_NATURE_H
#define NATURE_NATURE_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/norm.hpp>


namespace nature
{
    void size(int w, int h);
    void background(float c);
    typedef glm::vec4 Color;
    typedef glm::mat4 Matrix;
    typedef glm::vec3 Point;
    typedef glm::vec3 Vector;
    typedef struct Vertex
    {
        Point position;
        Point normal;
        Color color;
    } Vertex;

    void stroke(float c);
    void point(float x, float y);

    float random(float high);
    float random(float low, float high);
}

void setup();
void draw();
extern int width;
extern int height;

#include "AppRunner.h"
#define NATURE_MAIN() int main() { try { AppRunner app; return app(); } catch (const char* e) { cout << e << endl; } return EXIT_FAILURE; }

#endif //NATURE_NATURE_H
