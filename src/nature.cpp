//
// Created by Darren Mothersele on 05/05/2016.
//

#include "Window.h"
#include "Mesh.h"

namespace nature {
    void size(int w, int h) {
        Window::getWindow().setSize(w, h);
    }

    void background(float c) {
        Window::getWindow().clear(c);
    }

    void stroke(float c)
    {
        glColor3f(c, c, c);
    }

    void point(float x, float y)
    {
        Mesh t;
        t.addTriangle({x, y, 0}, {x, y, 0}, {x, y, 0}, {0, 0, 1}, {1, 1, 1, 1});
        t.bind();
        t.draw();
    }

    float random(float high)
    {
        return random(0, high);
    }

    float random(float low, float high)
    {
        return (rand() / (float)RAND_MAX) * high;
    }
}
