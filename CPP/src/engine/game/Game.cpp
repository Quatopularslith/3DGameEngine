//
// Created by Razim on 1/7/2016.
//

#include "Game.h"
#include "../input/Input.h"
#include <glfw3.h>
#include <iostream>


void Game::input(){

    if(Input::isKeyDown(GLFW_KEY_A)) printf("Key Pressed\n");
    if(Input::isMButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) printf("Button Pressed\n");

}

void Game::render(){

}

void Game::update(){

}