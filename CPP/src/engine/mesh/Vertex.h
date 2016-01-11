//
// Created by Razim on 1/9/2016.
//

#ifndef INC_3DGAMEENGINE_VERTEX_H
#define INC_3DGAMEENGINE_VERTEX_H

#include "../math/Vector3f.h"
class Vertex {
public:
    static const int SIZE = 3;
    Vertex(Vector3f pos1);
    Vector3f getPos();
    void setPos(Vector3f pos);
private:
    Vector3f pos = Vector3f(0,0,0);
};


#endif //INC_3DGAMEENGINE_VERTEX_H
