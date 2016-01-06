//
// Created by Razim on 1/6/2016.
//

#define GLEW_STATIC

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "../../glew/glew.h"
#include <glfw3.h>
#include "../window/Window.h"

bool Engine::running = false;
int Engine::FPS_CAP = 60;

void Engine::start() { if(!running) run(); }

void Engine::stop() { if(running) Engine::running = false; }

void Engine::run() {

    Engine::init();
    Window::createWindow(1280, 720, "3D Game Engine", NULL, NULL);
    Window::makeCurrentContext();
    Window::centerWindow();
    Window::showWindow();

    while(true) { Window::update(); }

}

void Engine::loop() {

}

void Engine::render(){

}

void Engine::cleanup() {

}

void Engine::init() {

    if(glewInit() != GL_TRUE){
        std::cout << "Glew failed to init" << std::endl;
        exit(-1);
    }

    if(glfwInit() != GL_TRUE){
        std::cout << "GLFW failed to init" << std::endl;
        exit(-1);
    }

}