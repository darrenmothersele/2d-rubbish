#include "nature.h"

using namespace nature;


class Walker {
    int x, y;

public:
    void move(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void step() {
        int choice = (int)random(4);
        if (choice == 0)
        {
            x++;
        } else if (choice == 1) {
            x--;
        } else if (choice == 2) {
            y++;
        } else {
            y--;
        }
    }
    void display() {
        stroke(0);
        point(x, y);
        cout << "Plot " << x << "x" << y << endl;
    }
};

Walker w;

void setup()
{
    size(640, 480);
    background(1);
    w.move(width / 2, height / 2);
}

void draw()
{
    w.step();
    w.display();
}


NATURE_MAIN()
