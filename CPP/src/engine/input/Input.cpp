//
// Created by Mnenmenth on 1/7/2016.
//

#include <tuple>
#include "Input.h"
#include "../window/Window.h"

std::array<Input::States, GLFW_KEY_LAST> Input::keyState;
std::array<Input::States, GLFW_MOUSE_BUTTON_LAST> Input::mButtonState;

//Keys

void Input::resetStates() {
    for(int i = 0; i < Input::keyState.size(); i++){
        Input::keyState[i] = Input::Idle;
    }
    for(int i = 0; i < Input::mButtonState.size(); i++){
        Input::mButtonState[i] = Input::Idle;
    }
}

bool Input::isKeyDown(int keyCode) {
    return keyState[keyCode] == Input::Press;
}

bool Input::isKeyReleased(int keyCode) {
    return keyState[keyCode] == Input::Release;
}

bool Input::isKeyPressed(int keyCode) {
    return keyState[keyCode] == Input::Press || keyState[keyCode] == Input::Repeat;
}

bool Input::isKeyHeldDown(int keyCode) {
    return keyState[keyCode] != Input::Release;
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    switch (action){
        case GLFW_REPEAT:
            Input::keyState[key] = Input::Repeat;
            break;
        case GLFW_PRESS:
            Input::keyState[key] = Input::Press;
            break;
        case GLFW_RELEASE:
        Input::keyState[key] = Input::Release;
            break;
        default:
        Input::keyState[key] = Input::Idle;
            break;
    }
}

//Mouse Buttons

bool Input::isMButtonDown(int mButtonCode) {
    return Input::mButtonState[mButtonCode] == Input::Press;
}

bool Input::isMButtonReleased(int mButtonCode) {
    return Input::mButtonState[mButtonCode] == Input::Release;
}

bool Input::isMButtonPressed(int mButtonCode) {
    return Input::mButtonState[mButtonCode] == Input::Press || Input::mButtonState[mButtonCode] == Input::Repeat;
}

bool Input::isMButtonHeldDown(int mButtonCode) {
    return Input::mButtonState[mButtonCode] != Input::Release;
}

void Input::mButton_callback(GLFWwindow *window, int button, int action, int mods) {
    switch (action){
        case GLFW_RELEASE:
        Input::mButtonState[button] = Input::Release;
            break;
        case GLFW_PRESS:
        Input::mButtonState[button] = Input::Press;
            break;
        case GLFW_REPEAT:
        Input::mButtonState[button] = Input::Repeat;
            break;
        default:
        Input::mButtonState[button] = Input::Idle;
            break;
    }
}

//Mouse Cursor
Input::CursorPos Input::getCursorPos(){
    Input::CursorPos pos;
    glfwGetCursorPos(Window::window, &pos.x, &pos.y);
    return pos;
}