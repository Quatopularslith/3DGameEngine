//
// Created by Mnenmenth on 1/6/2016.
//

#ifndef INC_3DGAMEENGINE_WINDOW_H
#define INC_3DGAMEENGINE_WINDOW_H

#include <glfw3.h>
#include <string>

class Window {
public:

    static GLFWwindow* window;
    static int width;
    static int height;
    static std::string title;
    static bool fullScreen;

    static GLFWwindow* createWindow(int width, int height, std::string title, bool fullScreen = false);
    static void setTitle(std::string title);
    static void showWindow();
    static void setWindowHint(int hint, int boolVal);
    static void centerWindow();
    static void makeCurrentContext();
    static void vsync(bool boolVal);
    static void update();
    static bool isCloseRequested();
    static void close();

};


#endif //INC_3DGAMEENGINE_WINDOW_H
