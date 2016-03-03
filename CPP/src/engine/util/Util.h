//
// Created by Razim on 3/2/2016.
//

#ifndef INC_3DGAMEENGINE_UTIL_H
#define INC_3DGAMEENGINE_UTIL_H


#include "../../glew/glew.h"
#include "../mesh/Vertex.h"
#include "../math/Matrix4f.h"
#include <array>

class Util {
public:
    /*static std::array<GLfloat> createFlippedBuffer(Vertex* vertices);
    static std::array<GLfloat> createFlippedBuffer(int* vertices);*/
    static GLfloat* createFlippedBuffer(Matrix4f value);
    static std::vector<std::string> splitString(std::string str, char delimiter);
private:
};


#endif //INC_3DGAMEENGINE_UTIL_H
