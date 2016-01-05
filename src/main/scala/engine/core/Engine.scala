package engine.core

import engine.window.Window
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWErrorCallback

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Engine {

  def start(): Unit ={
    Window.createWindow(1280, 720, "3D Engine")
  }

  def stop(): Unit ={

  }

  private def run(): Unit ={
    init()
  }

  private def init(): Unit ={

    glfwSetErrorCallback(GLFWErrorCallback.createPrint(System.err))

    if(glfwInit() != GLFW_TRUE) println("GLFW failed to init"); sys.exit()

  }

}
