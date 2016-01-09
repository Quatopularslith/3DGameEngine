//
// Created by Mnenmenth on 1/8/2016.
//

#include "Matrix4f.h"

Matrix4f::Matrix4f() {

}

Matrix4f Matrix4f::initIdentity(){
    Matrix4f::matrix[0][0] = 1; Matrix4f::matrix[0][1] = 0; Matrix4f::matrix[0][2] = 0; Matrix4f::matrix[0][3] = 0;
    Matrix4f::matrix[1][0] = 0; Matrix4f::matrix[1][1] = 1; Matrix4f::matrix[1][2] = 0; Matrix4f::matrix[1][3] = 0;
    Matrix4f::matrix[2][0] = 0; Matrix4f::matrix[2][1] = 0; Matrix4f::matrix[2][2] = 1; Matrix4f::matrix[2][3] = 0;
    Matrix4f::matrix[3][0] = 0; Matrix4f::matrix[3][1] = 0; Matrix4f::matrix[3][2] = 0; Matrix4f::matrix[3][3] = 1;
    return *this;
}

Matrix4f Matrix4f::mult(Matrix4f matrix) {
    Matrix4f res = Matrix4f();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res.set(i, j, Matrix4f::matrix[i][0] * matrix.get(0, j) +
                          Matrix4f::matrix[i][1] * matrix.get(1, j) +
                          Matrix4f::matrix[i][2] * matrix.get(2, j) +
                          Matrix4f::matrix[i][3] * matrix.get(3, j));
        }
    }
    return res;
}

std::vector<std::vector<float>> Matrix4f::getM() {
    return Matrix4f::matrix;
}

void Matrix4f::setM(std::vector<std::vector<float>> matrix) {
    Matrix4f::matrix = matrix;
}

float Matrix4f::get(int x, int y) {
    return Matrix4f::matrix[x][y];
}

void Matrix4f::set(int x, int y, float value) {
    Matrix4f::matrix[x][y] = value;
}