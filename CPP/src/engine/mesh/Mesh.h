//
// Created by Razim on 1/9/2016.
//

#ifndef INC_3DGAMEENGINE_MESH_H
#define INC_3DGAMEENGINE_MESH_H
#define GLEW_STATIC

#include "../../glew/glew.h"
#include "Vertex.h"

class Mesh {
public:
    Mesh();

    void addVertices(Vertex *vertices, int *indices);

    void draw();

private:
    GLuint vbo;
    GLuint ibo;
    int size;
};


#endif //INC_3DGAMEENGINE_MESH_H
