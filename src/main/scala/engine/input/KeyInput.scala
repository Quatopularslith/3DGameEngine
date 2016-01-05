package engine.input

import engine.core.Engine
import engine.window.Window
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWKeyCallback

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object KeyInput {

  def setKeyCallBack(): Unit ={
    glfwSetKeyCallback(Window.window, new GLFWKeyCallback {
      override def invoke(l: Long, i: Int, i1: Int, i2: Int, i3: Int): Unit = {

      }
    })
  }

}
