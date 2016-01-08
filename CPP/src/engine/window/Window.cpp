//
// Created by Razim on 1/6/2016.
//

#include "Window.h"
#include "../input/Input.h"
#include <iostream>

GLFWwindow *Window::window;
int Window::width;
int Window::height;
std::string Window::title;
bool Window::fullScreen;

GLFWwindow *Window::createWindow(int width, int height, std::string title, bool fullScreen) {
    if (fullScreen) {
        const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        Window::setWindowHint(GLFW_RED_BITS, vidmode->redBits);
        Window::setWindowHint(GLFW_GREEN_BITS, vidmode->greenBits);
        Window::setWindowHint(GLFW_BLUE_BITS, vidmode->blueBits);
        Window::setWindowHint(GLFW_REFRESH_RATE, vidmode->refreshRate);
        Window::window = glfwCreateWindow(vidmode->width, vidmode->height, title.c_str(), glfwGetPrimaryMonitor(),
                                          NULL);
        Window::fullScreen = true;
    } else {
        Window::window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    }
    if (!window) return window;
    else return 0;
}

void Window::setTitle(std::string title) {
    Window::title = title;
    glfwSetWindowTitle(Window::window, title.c_str());
}

void Window::showWindow() { glfwShowWindow(Window::window); }

void Window::setWindowHint(int hint, int value) { glfwWindowHint(hint, value); }

void Window::centerWindow() {
    if (!fullScreen) {
        const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowPos(Window::window, (vidmode->width - Window::height) / 2, (vidmode->height - Window::height) / 2);
    }
}

void Window::makeCurrentContext() { glfwMakeContextCurrent(Window::window); }

void Window::vsync(bool boolVal) {
    if (boolVal) {
        glfwSwapInterval(1);
    } else {
        glfwSwapInterval(0);
    }
}

void Window::update() { glfwSwapBuffers(Window::window); }

bool Window::isCloseRequested() {
    return Input::isKeyPressed(GLFW_KEY_ESCAPE) || glfwWindowShouldClose(Window::window);
}

void Window::close() { glfwDestroyWindow(Window::window); }