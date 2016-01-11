//
// Created by Razim on 1/9/2016.
//

#include "Vertex.h"
#include "../math/Vector3f.h"

Vertex::Vertex(Vector3f pos) {
    Vertex::pos = pos;
}

Vector3f Vertex::getPos() {
    return Vertex::pos;
}

void Vertex::setPos(Vector3f pos) {
    Vertex::pos = pos;
}