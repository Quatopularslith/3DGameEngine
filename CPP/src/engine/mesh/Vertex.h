//
// Created by Razim on 1/9/2016.
//

#ifndef INC_3DGAMEENGINE_VERTEX_H
#define INC_3DGAMEENGINE_VERTEX_H

#include "../math/Vector3f.h"

class Vertex {
public:
    static const int SIZE = 3;

    Vertex(Vector3f position);

    Vector3f getPos();

    void setPos(Vector3f position);

private:
    Vector3f pos;
};


#endif //INC_3DGAMEENGINE_VERTEX_H
