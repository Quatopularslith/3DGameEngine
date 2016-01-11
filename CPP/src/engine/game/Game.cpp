//
// Created by Mnenmenth on 1/7/2016.
//

#include "Game.h"
#include "../input/Input.h"
#include "../mesh/Mesh.h"
#include "../mesh/Vertex.h"
#include <glfw3.h>
#include <iostream>

Game::Game() {
    Game::mesh = Mesh();
    Vertex data[] =  {Vertex(Vector3f(-1,-1,0)),
                     Vertex(Vector3f(0,1,0)),
                     Vertex(Vector3f(1,-1,0))};

    printf("hi\n");
    Game::mesh.addVertices(data);
}

void Game::input(){

    if(Input::isKeyDown(GLFW_KEY_A)) printf("Key Pressed\n");
    if(Input::isMButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) printf("Button Pressed\n");

}

void Game::render(){

}

void Game::update(){
    Game::mesh.draw();
}