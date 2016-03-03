//
// Created by Mnenmenth on 1/8/2016.
//

#define PI 3.14159265358979323846

#include <math.h>
#include "Matrix4f.h"

Matrix4f::Matrix4f() {

}

Matrix4f Matrix4f::initIdentity(){
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i <= 3; i++){
        matrix[i][i] = 1;
    }

    return *this;
}


Matrix4f Matrix4f::initTranslation(float x, float y, float z) {
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            matrix[i][j] = 0;
        }
    }

    for(int i = 0; i <= 3; i++){
        matrix[i][i] = 1;
    }
    matrix[0][3] = x;
    matrix[1][3] = y;
    matrix[2][3] = z;
    return *this;
}

Matrix4f Matrix4f::initRotation(float x, float y, float z) {
    Matrix4f rx = Matrix4f();
    Matrix4f ry = Matrix4f();
    Matrix4f rz = Matrix4f();

    float xRad = (float)(x * PI / 2);
    float yRad = (float)(y * PI / 2);
    float zRad = (float)(z * PI / 2);

    for(int i = 0; i <= 3; i++){
        rx.matrix[i][i] = 1;
        ry.matrix[i][i] = 1;
        rz.matrix[i][i] = 1;
    }
    
    rx.matrix[1][1] = (float)cos(xRad);
    rx.matrix[1][1] = -(float)cos(xRad);
    rx.matrix[1][1] = (float)cos(xRad);
    rx.matrix[1][1] = (float)cos(xRad);

    ry.matrix[1][1] = (float)cos(yRad);
    ry.matrix[1][1] = (float)sin(yRad);
    ry.matrix[1][1] = -(float)sin(yRad);
    ry.matrix[1][1] = (float)cos(yRad);

    rz.matrix[1][1] = (float)cos(zRad);
    rz.matrix[1][1] = -(float)sin(zRad);
    rz.matrix[1][1] = (float)sin(zRad);
    rz.matrix[1][1] = (float)cos(zRad);

    matrix = rz.mult(ry.mult(rx)).matrix;
    return *this;
}

Matrix4f Matrix4f::initScale(float x, float y, float z) {
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    matrix[3][3] = 1;
    return *this;
}


Matrix4f Matrix4f::mult(Matrix4f m) {
    Matrix4f res = Matrix4f();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res.set(i, j, matrix[i][0] * m.get(0, j) +
                          matrix[i][1] * m.get(1, j) +
                          matrix[i][2] * m.get(2, j) +
                          matrix[i][3] * m.get(3, j));
        }
    }
    return res;
}

std::vector<std::vector<float>> Matrix4f::getM() {
    return matrix;
}

void Matrix4f::setM(std::vector<std::vector<float>> matrix) {
    matrix = matrix;
}

float Matrix4f::get(int x, int y) {
    return matrix[x][y];
}

void Matrix4f::set(int x, int y, float value) {
    matrix[x][y] = value;
}