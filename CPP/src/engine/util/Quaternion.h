//
// Created by Razim on 1/9/2016.
//

#ifndef INC_3DGAMEENGINE_QUATERNION_H
#define INC_3DGAMEENGINE_QUATERNION_H


#include "Vector3f.h"

class Quaternion {
public:
    Quaternion(float x, float y, float z, float w);

    float length();
    Quaternion normalize();
    Quaternion conjugate();

    Quaternion mult(Quaternion q);
    Quaternion mult(Vector3f v);

    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    float getZ();
    void setZ(float z);
    float getW();
    void setW(float w);
private:
    float x, y, z, w;
};


#endif //INC_3DGAMEENGINE_QUATERNION_H
