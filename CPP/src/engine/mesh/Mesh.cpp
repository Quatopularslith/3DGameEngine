//
// Created by Razim on 1/9/2016.
//

#include "Mesh.h"
#define GLEW_STATIC

#include "../../glew/glew.h"
#include "Vertex.h"

Mesh::Mesh() {}

void Mesh::addVertices(Vertex vertices[]){
    Mesh::size = sizeof(vertices) * Vertex::SIZE;
    printf("Hi\n");

    GLuint vbo;
    glGenBuffers(Mesh::size, &vbo);
    Mesh::vbo = vbo;
    printf("Hi\n");

    glBindBuffer(GL_ARRAY_BUFFER, Mesh::vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Mesh::draw(){

    glEnableVertexAttribArray(0);
    printf("Hi\n");
    glBindBuffer(GL_ARRAY_BUFFER, Mesh::vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, Mesh::size);

    glDisableVertexAttribArray(0);
}