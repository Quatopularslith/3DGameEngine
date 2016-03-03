//
// Created by Razim on 1/9/2016.
//

#include "Vertex.h"

Vertex::Vertex(Vector3f position) : pos(position){ }

Vector3f Vertex::getPos() {
    return pos;
}

void Vertex::setPos(Vector3f position) {
    pos = position;
}