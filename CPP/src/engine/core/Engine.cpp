//
// Created by Mnenmenth on 1/6/2016.
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
#include "../util/RenderUtil.h"
#include <chrono>
#include <thread>

bool Engine::running = false;
int Engine::FPS_CAP = 60;
Game* Engine::game;

void Engine::start() { if(!running) run(); }

void Engine::stop() { if(running) running = false; }

void error_callback(int error, const char* description){
    std::cout << "Description: " << description << std::endl << "Error: " << stderr << std::endl;
}

void Engine::run() {

    running = true;
    glfwSetErrorCallback(error_callback);

    if(glfwInit() != GL_TRUE){
        std::cout << "GLFW failed to initialize" << std::endl;
        exit(-1);
    }

    Window::createWindow(1280, 720, "3D Game Engine");
    Window::makeCurrentContext();
    Window::centerWindow();
    Window::showWindow();

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cout << "Glew failed to initialize" << std::endl;
        exit(-1);
    }
    init();

    game = new Game;
    RenderUtil::initGraphics();
    loop();
}

void Engine::loop() {
    
    Window::vsync(false);

    int frames = 0;
    long long int frameCounter = 0;
    double frameTime = 1.0 / FPS_CAP;
    long long int lastTime = Time::getTime();
    double unprocessedTime = 0;

    while(running){

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

            game->input();
            game->update();

            if(frameCounter >= Time::NANO_SECOND){
                std::cout << frames << std::endl;
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
    RenderUtil::clearScreen();
    game->render();
    Window::update();
}

void Engine::cleanup(){
    Window::close();
    glfwTerminate();
}

void Engine::init(){

    glfwSetKeyCallback(Window::window, Input::key_callback);
    glfwSetMouseButtonCallback(Window::window, Input::mButton_callback);
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

Engine::~Engine(){
    delete game;
}