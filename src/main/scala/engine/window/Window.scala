package engine.window

import org.lwjgl.glfw.GLFW._
/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Window {

  var window: Long = _

  var width = 0
  var height = 0

  def createWindow(width1: Int, height1: Int, title: String): Long = {
    width = width1
    height = height1
    window = glfwCreateWindow(width, height, title, null, null)
    if(window != 0) window
    else sys.exit(); 0
  }

  def showWindow() = glfwShowWindow(window)

  def setWindowHint(hint: Int, bool: Int): Unit ={
    glfwWindowHint(hint, bool)
  }

  def centerWindow(): Unit ={
    val vidmode = glfwGetVideoMode(glfwGetWindowMonitor(window))
    glfwSetWindowPos(window, (vidmode.width - width) / 2, (vidmode.height - height) / 2)
  }

  def makeCurrentContext(): Unit = glfwMakeContextCurrent(window)

  def vsync(bool: Boolean): Unit = if(bool) glfwSwapInterval(1) else glfwSwapInterval(0)

  def update(): Unit = glfwSwapBuffers(window)

  def isCloseRequested = glfwWindowShouldClose(window)

  def destroy(): Unit ={
    glfwDestroyWindow(window)
  }
}
