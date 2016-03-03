//
// Created by Razim on 1/9/2016.
//

#include "Mesh.h"
#define GLEW_STATIC

#include "../../glew/glew.h"
#include "Vertex.h"

Mesh::Mesh() {}

void Mesh::addVertices(Vertex* vertices, int* indices){
    size = sizeof(vertices) * Vertex::SIZE;

    glGenBuffers(size, &vbo);
    glGenBuffers(size, &ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Mesh::draw(){
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, (void*)0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
}