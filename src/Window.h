//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef NATURE_WINDOW_H
#define NATURE_WINDOW_H

#include "nature.h"

extern glm::mat4 projection;

class Window {
    GLFWwindow* window;
    int screenWidth, screenHeight;

    Window(const int width = 320, const int height = 240);

    Window(Window const&) = delete;
    void operator=(Window const&) = delete;

    static void resizeCallback(GLFWwindow* window, int w, int h);

public:
    ~Window() {}

    int shouldClose();
    void clear();
    void clear(float c);

    void update();
    void setClearColor(nature::Color c);

    static Window& getWindow() {
        static Window instance;
        return instance;
    }

    void setSize(int w, int h);
};


#endif //NATURE_WINDOW_H
