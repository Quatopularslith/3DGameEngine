//
// Created by Razim on 1/6/2016.
//

#include "Window.h"
#include <string>
#include <glfw3.h>
#include <iostream>

GLFWwindow* Window::window;
int Window::width;
int Window::height;
std::string Window::title;
bool Window::fullScreen;

GLFWwindow* Window::createWindow(int width, int height, std::string title, bool fullScreen = false, GLFWmonitor *monitor = glfwGetPrimaryMonitor()){
    if(fullScreen){
        const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
        Window::window = glfwCreateWindow(vidmode->width, vidmode->height, title.c_str(), monitor, NULL);
        std::cout << "hello" << std::endl;
        Window::fullScreen = true;
    }else{
        Window::window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    }
    if(!window) return window;
    else return 0;
}

void Window::setTitle(std::string title) {
    Window::title = title;
    glfwSetWindowTitle(Window::window, title.c_str());
}

void Window::showWindow() { glfwShowWindow(Window::window); }

void Window::setWindowHint(int hint, int boolVal) { glfwWindowHint(hint, boolVal); }

void Window::centerWindow() {
    if(!fullScreen) {
        const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetWindowMonitor(Window::window));
        glfwSetWindowPos(Window::window, (vidmode->width - Window::width) / 2, (vidmode->height - Window::height) / 2);
    }
}

void Window::makeCurrentContext() { glfwMakeContextCurrent(Window::window); }

void Window::vsync(bool boolVal) {
    if(boolVal){
        glfwSwapInterval(1);
    }else{
        glfwSwapInterval(0);
    }
}

void Window::update() { glfwSwapBuffers(Window::window); }

void Window::isCloseRequested() {  }

void Window::close() { glfwDestroyWindow(Window::window); }