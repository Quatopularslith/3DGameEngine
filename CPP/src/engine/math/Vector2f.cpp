//
// Created by Mnenmenth on 1/7/2016.
//

#include "Vector2f.h"
#include <sstream>
#include <math.h>

Vector2f::Vector2f(float x, float y) {
    Vector2f::x = x;
    Vector2f::y = y;
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

std::string Vector2f::toString() {
    std::stringstream stream;
    stream << "(x: " << Vector2f::x << ", y: " << Vector2f::y << ")";
    return stream.str();
}

float Vector2f::length() {
    return (float) sqrt(Vector2f::x * Vector2f::x + Vector2f::y * Vector2f::y);
}

float Vector2f::dot(Vector2f v) {
    return Vector2f::x * v.getX() + Vector2f::y * v.getY();
}

Vector2f Vector2f::normalize() {
    float length = Vector2f::length();
    Vector2f::x /= length;
    Vector2f::y /= length;
    return *this;
}

Vector2f Vector2f::rotate(float angle) {
    double radians = angle * (3.141592653 / 180);
    double cos_ = cos(radians);
    double sin_ = sin(radians);
    return Vector2f((float) (Vector2f::x * cos_ - Vector2f::y * sin_),
                    (float) (Vector2f::x * sin_ + Vector2f::y * cos_));
}

Vector2f Vector2f::add(Vector2f v) {
    return Vector2f(Vector2f::x + v.getX(), Vector2f::y + v.getY());
}

Vector2f Vector2f::add(float v) {
    return Vector2f(Vector2f::x + v, Vector2f::y + v);
}

Vector2f Vector2f::sub(Vector2f v) {
    return Vector2f(Vector2f::x - v.getX(), Vector2f::y - v.getY());
}

Vector2f Vector2f::sub(float v) {
    return Vector2f(Vector2f::x - v, Vector2f::y - v);
}

Vector2f Vector2f::mult(Vector2f v) {
    return Vector2f(Vector2f::x * v.getX(), Vector2f::y * v.getY());
}

Vector2f Vector2f::mult(float v) {
    return Vector2f(Vector2f::x * v, Vector2f::y * v);
}

Vector2f Vector2f::div(Vector2f v) {
    return Vector2f(Vector2f::x / v.getX(), Vector2f::y / v.getY());
}

Vector2f Vector2f::div(float v) {
    return Vector2f(Vector2f::x / v, Vector2f::y / v);
}