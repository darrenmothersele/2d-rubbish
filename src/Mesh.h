//
// Created by Darren Mothersele on 05/05/2016.
//

#ifndef NATURE_MESH_H
#define NATURE_MESH_H

#include "nature.h"

using namespace nature;

class Mesh
{
    GLuint vao, vbo, ebo;
public:
    vector<Vertex> vertices;
    vector<GLuint> indices;
    void draw();
    void bind();

    void addTriangle(Vertex v1, Vertex v2, Vertex v3);
    void addTriangle(Point p1, Point p2, Point p3, Vector n, Color c);
    void addQuad(Point p1, Point p2, Point p3, Point p4, Vector n, Color c);
    void addQuad(float size, float distance, Vector n, Color c);
};



#endif //NATURE_MESH_H
