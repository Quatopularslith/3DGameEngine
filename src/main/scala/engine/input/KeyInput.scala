package engine.input

import engine.window.Window
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWKeyCallback

import KeyHandler.isKeyDown
import KeyHandler.isKeyPressed
import KeyHandler.isKeyReleased
import KeyHandler.isKeyRepeated

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object KeyInput {

  def setKeyCallBack(): Unit = {
    glfwSetKeyCallback(Window.window, KeyHandler)
  }

  def input(): Unit ={

    if(isKeyDown(GLFW_KEY_W)) println("W")
    if(isKeyDown(GLFW_KEY_S)) println("S")

  }

}
