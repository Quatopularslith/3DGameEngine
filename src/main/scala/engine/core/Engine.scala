package engine.core

import engine.input.{KeyInput, KeyHandler}
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

  private var running = false

  def start(): Unit = {

    if(running) None
    else run()

  }

  def stop(): Unit = {

    if(!running) None
    else running = false

  }

  private def run(): Unit = {

    running = true

    init()
    Window.createWindow(1280, 720, "3D Engine")
    Window.makeCurrentContext()
    Window.centerWindow()
    Window.showWindow()

    KeyInput.setKeyCallBack()

    loop()
  }

  private def loop(): Unit = {

    Window.vsync(false)

    while (running) {
      Window.update()

      if(Window.isCloseRequested) stop()

      KeyInput.input()

      KeyHandler.resetKeyStates()
      glfwPollEvents()
    }

    cleanUp()

  }

  private def cleanUp(): Unit ={
    Window.close()
    glfwTerminate()
  }

  private def init(): Unit = {

    glfwSetErrorCallback(GLFWErrorCallback.createPrint(System.err))

    if (glfwInit() != GLFW_TRUE) {
      println("GLFW failed to init"); sys.exit()
    }

  }

}
