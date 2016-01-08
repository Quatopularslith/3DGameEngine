//
// Created by Razim on 1/7/2016.
//

#ifndef INC_3DGAMEENGINE_VECTOR2F_H
#define INC_3DGAMEENGINE_VECTOR2F_H

#include <string>
class Vector2f {
public:
    Vector2f(float x, float y);
    std::string toString();
    float length();
    float dot(Vector2f r);
    Vector2f normalize();

    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
private:
    float x,y;
};


#endif //INC_3DGAMEENGINE_VECTOR2F_H
