//
// Created by Razim on 3/2/2016.
//

#ifndef INC_3DGAMEENGINE_TRANSFORMATION_H
#define INC_3DGAMEENGINE_TRANSFORMATION_H


#include "../math/Vector3f.h"
#include "../math/Matrix4f.h"

class Transformation {
public:
    Vector3f translation;
    Vector3f rotation;
    Vector3f scale;
    Matrix4f transformationmatrix();
private:
};


#endif //INC_3DGAMEENGINE_TRANSFORMATION_H
