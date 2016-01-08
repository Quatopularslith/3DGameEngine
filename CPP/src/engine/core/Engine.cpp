//
// Created by Razim on 1/6/2016.
//

#define GLEW_STATIC

#include <iostream>
#include <stdlib.h>
#include "Engine.h"
#include "../../glew/glew.h"
#include <glfw3.h>
#include <stdio.h>
#include "../window/Window.h"
#include "../input/Input.h"
#include "../game/Game.h"
#include "../util/Time.h"
#include "../util/Vector2f.h"
#include <chrono>
#include <thread>

bool Engine::running = false;
int Engine::FPS_CAP = 60;

void Engine::start() { if(!running) run(); }

void Engine::stop() { if(running) Engine::running = false; }

void Engine::run() {

    running = true;

    Engine::glInit();
    Window::createWindow(1280, 720, "3D Game Engine");
    Window::makeCurrentContext();
    Window::centerWindow();
    Window::showWindow();
    Engine::init();

    Engine::loop();
}

void Engine::loop() {
    
    Window::vsync(false);

    int frames = 0;
    long long int frameCounter = 0;
    double frameTime = 1.0 / Engine::FPS_CAP;
    long long int lastTime = Time::getTime();
    double unprocessedTime = 0;

    while(Engine::running){

        bool shouldRender = false;

        long long int startTime = Time::getTime();
        long long int passedTime = startTime - lastTime;
        lastTime = startTime;

        unprocessedTime += passedTime / (double)Time::NANO_SECOND;
        frameCounter += passedTime;

        while(unprocessedTime > frameTime){
            Input::resetStates();
            glfwPollEvents();

            shouldRender = true;
            unprocessedTime -= frameTime;
            if(Window::isCloseRequested()) stop();

            Time::setDelta(frameTime);

            Game::input();
            Game::update();

            if(frameCounter >= Time::NANO_SECOND){
                frames = 0;
                frameCounter = 0;
            }
        }

        if(shouldRender){
            render();
            frames += 1;
        }else{
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    cleanup();
}

void Engine::render(){
    Game::render();
    Window::update();
}

void Engine::cleanup(){
    Window::close();
    glfwTerminate();
}

void error_callback(int error, const char* description){
    std::cout << "Description: " << description << std::endl << "Error: " << stderr << std::endl;
}

void Engine::init(){

    glfwSetKeyCallback(Window::window, Input::key_callback);
    glfwSetMouseButtonCallback(Window::window, Input::mButton_callback);
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Engine::glInit(){

    glfwSetErrorCallback(error_callback);

    if(glewInit() != GL_TRUE){
        std::cout << "Glewa intializum ad aborior" << std::endl;
        exit(-1);
    }

    if(glfwInit() != GL_TRUE){
        std::cout << "GLFWa intializum ad aborior" << std::endl;
        exit(-1);
    }

}