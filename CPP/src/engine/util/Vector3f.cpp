//
// Created by Mnenmenth on 1/8/2016.
//

#include "Vector3f.h"
#include <math.h>
#include <sstream>
#include <string>

Vector3f::Vector3f(float x, float y, float z) {
    Vector3f::x = x;
    Vector3f::y = y;
    Vector3f::z = z;
}

void Vector3f::setX(float x) {
    Vector3f::x = x;
}

void Vector3f::setY(float y) {
    Vector3f::y = y;
}

void Vector3f::setZ(float z) {
    Vector3f::z = z;
}

float Vector3f::getX() {
    return Vector3f::x;
}

float Vector3f::getY() {
    return Vector3f::y;
}

float Vector3f::getZ() {
    return Vector3f::z;
}

std::string Vector3f::toString(){
    std::stringstream stream;
    stream << "(x: " << Vector3f::x << ", y: " << Vector3f::y << ", z: " << Vector3f::z << ")";
    return stream.str();
}

float Vector3f::length(){
    return (float)sqrt(pow(Vector3f::x, 2) + pow(Vector3f::y, 2) + pow(Vector3f::z, 2));
}

float Vector3f::dot(Vector3f v){
    return Vector3f::x * v.getX() + Vector3f::y * v.getY() + Vector3f::z * v.getZ();
}

Vector3f Vector3f::cross(Vector3f v){
    float x = Vector3f::y * v.getZ() - Vector3f::z * v.getY();
    float y = Vector3f::z * v.getX() - Vector3f::x * v.getZ();
    float z = Vector3f::x * v.getY() - Vector3f::y * v.getX();
    return Vector3f(x, y, z);
}

Vector3f Vector3f::normalize() {
    Vector3f::x /= length();
    Vector3f::y /= length();
    Vector3f::z /= length();
    return *this;
}

Vector3f Vector3f::rotate(float angle) {
    return NULL;
}

Vector3f Vector3f::add(Vector3f v) {
    return Vector3f(Vector3f::x + v.getX(), Vector3f::y + v.getY(), Vector3f::z + v.getZ());
}

Vector3f Vector3f::add(float v){
    return Vector3f(Vector3f::x + v, Vector3f::y + v, Vector3f::z + v);
}

Vector3f Vector3f::sub(Vector3f v) {
    return Vector3f(Vector3f::x - v.getX(), Vector3f::y - v.getY(), Vector3f::z - v.getZ());
}

Vector3f Vector3f::sub(float v){
    return Vector3f(Vector3f::x - v, Vector3f::y - v, Vector3f::z - v);
}

Vector3f Vector3f::mult(Vector3f v) {
    return Vector3f(Vector3f::x * v.getX(), Vector3f::y * v.getY(), Vector3f::z * v.getZ());
}

Vector3f Vector3f::mult(float v){
    return Vector3f(Vector3f::x * v, Vector3f::y * v, Vector3f::z * v);
}
Vector3f Vector3f::div(Vector3f v) {
    return Vector3f(Vector3f::x / v.getX(), Vector3f::y / v.getY(), Vector3f::z / v.getZ());
}

Vector3f Vector3f::div(float v){
    return Vector3f(Vector3f::x / v, Vector3f::y / v, Vector3f::z / v);
}