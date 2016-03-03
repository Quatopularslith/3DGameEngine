//
// Created by Mnenmenth on 1/7/2016.
//

#include "Game.h"
#include "../util/ResourceLoader.h"
#include "../input/Input.h"
#include "../util/Time.h"
#include <iostream>
#include <math.h>

Game::Game() {
    mesh = ResourceLoader::loadMesh("cube.obj");

    transform = Transformation();
    shader = Shader();

    shader.addVertexShader(ResourceLoader::loadShader("basicVertex.glsl"));
    shader.addFragmentShader(ResourceLoader::loadShader("fragmentShader.glsl"));
    shader.compileShader();
    shader.addUniform("transform");

}

void Game::input(){

    if(Input::isKeyDown(GLFW_KEY_UP)) std::cout <<"PRESSED UP" << std::endl;
    if(Input::isKeyReleased(GLFW_KEY_UP)) std::cout <<"RELEASED UP" << std::endl;
    if(Input::isMButtonDown(GLFW_MOUSE_BUTTON_LEFT)) std::cout <<"MOUSE DOWN" << std::endl;
    if(Input::isMButtonReleased(GLFW_MOUSE_BUTTON_LEFT)) std::cout <<"MOUSE UP" << std::endl;

}

void Game::render(){

    shader.bind();
    shader.setUniformm("transform", transform.transformationmatrix());
    mesh.draw();

}

void Game::update(){
    delta += (float)Time::delta;
    double sinDelta = sin(delta);
    transform.translation = Vector3f((float)sinDelta, 0, 0);
    transform.rotation = Vector3f(0, (float)sin(delta) * 90, (float)sinDelta * 180);
    transform.scale = Vector3f((float)(0.7 * sinDelta), (float)(0.7 * sinDelta), (float)(0.7 * sinDelta));
}