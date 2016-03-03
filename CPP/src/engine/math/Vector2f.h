//
// Created by Mnenmenth on 1/7/2016.
//

#ifndef INC_3DGAMEENGINE_VECTOR2F_H
#define INC_3DGAMEENGINE_VECTOR2F_H

#include <string>

class Vector2f {
public:
    Vector2f(float x, float y);

    void setX(float x);

    void setY(float y);

    float getX();

    float getY();

    std::string toString();

    float length();

    float dot(Vector2f v);

    Vector2f normalize();

    Vector2f rotate(float angle);

    Vector2f add(Vector2f v);

    Vector2f add(float v);

    Vector2f sub(Vector2f v);

    Vector2f sub(float v);

    Vector2f mult(Vector2f v);

    Vector2f mult(float v);

    Vector2f div(Vector2f v);

    Vector2f div(float v);

private:
    float x, y;
};


#endif //INC_3DGAMEENGINE_VECTOR2F_H
