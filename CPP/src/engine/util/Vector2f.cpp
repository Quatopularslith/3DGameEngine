//
// Created by Razim on 1/7/2016.
//

#include "Vector2f.h"
#include <string>
#include <sstream>
#include <math.h>

Vector2f::Vector2f(float x, float y){
    Vector2f::x = x;
    Vector2f::y = y;
}

std::string Vector2f::toString(){
    std::stringstream stream;
    stream << "(x: " << Vector2f::x << ", y: " << Vector2f::y << ")";
    return stream.str();
}

float Vector2f::length(){
    return (float)sqrt(Vector2f::x * Vector2f::x + Vector2f::y * Vector2f::y);
}

float Vector2f::dot(Vector2f v){
    return Vector2f::x * v.getX() + Vector2f::y * v.getY();
}

Vector2f Vector2f::normalize() {
    Vector2f::x /= length();
    Vector2f::y /= length();
    return *this;
}

void Vector2f::setX(float x) {
    Vector2f::x = x;
}

void Vector2f::setY(float y) {
    Vector2f::y = y;
}

float Vector2f::getX() {
    return Vector2f::x;
}

float Vector2f::getY() {
    return Vector2f::y;
}