#include <iostream>
#define GLEW_STATIC

#include "../glew/glew.h"
#include "../engine/core/Engine.h"
#include <glfw3.h>
#include <chrono>
#include <stdio.h>

using namespace std;

int main() {
    Engine::start();
    return 0;
}