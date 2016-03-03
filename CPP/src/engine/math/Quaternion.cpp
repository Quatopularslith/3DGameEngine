//
// Created by Razim on 1/9/2016.
//

#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion(float x, float y, float z, float w) {
    Quaternion::x = x;
    Quaternion::y = y;
    Quaternion::z = z;
    Quaternion::w = w;
}

float Quaternion::length() {
    return (float) sqrt(pow(Quaternion::x, 2) + pow(Quaternion::y, 2) + pow(Quaternion::z, 2) + pow(Quaternion::w, 2));
}

Quaternion Quaternion::normalize() {
    float length = Quaternion::length();
    Quaternion::x /= length;
    Quaternion::y /= length;
    Quaternion::z /= length;
    Quaternion::w /= length;
    return *this;
}

Quaternion Quaternion::conjugate() {
    return Quaternion(-Quaternion::x, -Quaternion::y, -Quaternion::z, w);
}

Quaternion Quaternion::mult(Quaternion q) {
    float w = Quaternion::w * q.getW() - Quaternion::x * q.getX() - Quaternion::y * q.getY() - Quaternion::z * q.getZ();
    float x = Quaternion::x * q.getW() + Quaternion::w * q.getX() + Quaternion::y * q.getZ() - Quaternion::z * q.getY();
    float y = Quaternion::y * q.getW() + Quaternion::w * q.getY() + Quaternion::z * q.getX() - Quaternion::x * q.getZ();
    float z = Quaternion::z * q.getW() + Quaternion::w * q.getZ() + Quaternion::x * q.getY() - Quaternion::y * q.getZ();
    return Quaternion(x, y, z, w);
}

Quaternion Quaternion::mult(Vector3f v) {
    float w = -Quaternion::x * v.getX() - Quaternion::y * v.getY() - Quaternion::z * v.getZ();
    float x = Quaternion::w * v.getX() + Quaternion::y * v.getZ() - Quaternion::z * v.getY();
    float y = Quaternion::w * v.getY() + Quaternion::z * v.getX() - Quaternion::x * v.getZ();
    float z = Quaternion::w * v.getZ() + Quaternion::x * v.getY() - Quaternion::y * v.getX();
    return Quaternion(x, y, z, w);
}

float Quaternion::getX() {
    return Quaternion::x;
}

void Quaternion::setX(float x) {
    Quaternion::x = x;
}

float Quaternion::getY() {
    return Quaternion::y;
}

void Quaternion::setY(float y) {
    Quaternion::y = y;
}

float Quaternion::getZ() {
    return Quaternion::z;
}

void Quaternion::setZ(float z) {
    Quaternion::z = z;
}

float Quaternion::getW() {
    return Quaternion::w;
}

void Quaternion::setW(float w) {
    Quaternion::w = w;
}