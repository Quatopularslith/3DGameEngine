//
// Created by Razim on 1/8/2016.
//

#ifndef INC_3DGAMEENGINE_VECTOR3F_H
#define INC_3DGAMEENGINE_VECTOR3F_H

#include <string>
class Vector3f {
public:
    Vector3f(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);
    float getX();
    float getY();
    float getZ();

    std::string toString();
    float length();
    float dot(Vector3f v);
    Vector3f cross(Vector3f v);
    Vector3f normalize();
    Vector3f rotate(float angle);

    Vector3f add(Vector3f v);
    Vector3f add(float v);
    Vector3f sub(Vector3f v);
    Vector3f sub(float v);
    Vector3f mult(Vector3f v);
    Vector3f mult(float v);
    Vector3f div(Vector3f v);
    Vector3f div(float v);
private:
    float x, y, z;
};


#endif //INC_3DGAMEENGINE_VECTOR3F_H
