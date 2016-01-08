//
// Created by Razim on 1/7/2016.
//

#ifndef INC_3DGAMEENGINE_Input_H
#define INC_3DGAMEENGINE_Input_H

#include <glfw3.h>
#include <array>

class Input {
public:
    static void resetStates();

    //Keys
    static bool isKeyDown(int keyCode);
    static bool isKeyReleased(int keyCode);
    static bool isKeyPressed(int keyCode);
    static bool isKeyHeldDown(int keyCode);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    //Mouse Buttons
    static bool isMButtonDown(int mButtonCode);
    static bool isMButtonReleased(int mButtonCode);
    static bool isMButtonPressed(int mButtonCode);
    static bool isMButtonHeldDown(int mButtonCode);
    static void mButton_callback(GLFWwindow* window, int button, int action, int mods);

    //Mouse Cursor

    typedef struct {
        double x,y;
    }CursorPos;

    static CursorPos getCursorPos();

private:
    typedef enum { Idle, Release, Press, Repeat } States;
    static std::array<Input::States, GLFW_KEY_LAST> keyState;
    static std::array<Input::States, GLFW_MOUSE_BUTTON_LAST> mButtonState;

};


#endif //INC_3DGAMEENGINE_Input_H
