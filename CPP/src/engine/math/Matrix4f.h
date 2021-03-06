//
// Created by Mnenmenth on 1/8/2016.
//

#ifndef INC_3DGAMEENGINE_MATRIX4F_H
#define INC_3DGAMEENGINE_MATRIX4F_H

#include <vector>

class Matrix4f {

public:
    Matrix4f();

    Matrix4f initIdentity();

    Matrix4f initTranslation(float x, float y, float z);

    Matrix4f initRotation(float x, float y, float z);

    Matrix4f initScale(float x, float y, float z);

    Matrix4f mult(Matrix4f matrix);

    void setM(std::vector<std::vector<float>> m);

    std::vector<std::vector<float>> getM();

    float get(int x, int y);

    void set(int x, int y, float value);

private:
    std::vector<std::vector<float>> matrix;
};


#endif //INC_3DGAMEENGINE_MATRIX4F_H
