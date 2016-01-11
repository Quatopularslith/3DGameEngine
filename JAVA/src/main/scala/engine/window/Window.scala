package engine.window

import engine.input.Input
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWVidMode

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Window {

  var window: Long = _

  var width: Int = 0
  var height: Int = 0
  var title: String = ""
  var fullScreen = false

  def createWindow(width1: Int, height1: Int, title1: String, fullScreen1: Boolean = false, monitor: Long = glfwGetPrimaryMonitor()): Long = {
    width = width1
    height = height1
    title = title1
    if (fullScreen1) {
      val vidmode = glfwGetVideoMode(monitor)
      window = glfwCreateWindow(vidmode.width(), vidmode.height, title, monitor, null.asInstanceOf[Long])
      fullScreen = true
    } else
      window = glfwCreateWindow(width, height, title, null.asInstanceOf[Long], null.asInstanceOf[Long])
    if (window != 0) window
    else {
      sys.exit()
      0.asInstanceOf[Long]
    }
  }

  def setTitle(title1: String): Unit = {
    title = title1
    glfwSetWindowTitle(window, title)
  }

  def showWindow() = glfwShowWindow(window)

  def setWindowHint(hint: Int, bool: Int): Unit = glfwWindowHint(hint, bool)

  def centerWindow(): Unit = {
    if (!fullScreen) {
      var vidmode: GLFWVidMode = glfwGetVideoMode(glfwGetPrimaryMonitor())
      try {
        vidmode = glfwGetVideoMode(glfwGetWindowMonitor(window))
      } catch {
        case e: NullPointerException => vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor())
      }
      glfwSetWindowPos(window, (vidmode.width - width) / 2, (vidmode.height - height) / 2)
    }
  }

  def makeCurrentContext(): Unit = glfwMakeContextCurrent(window)

  def vsync(bool: Boolean): Unit = if (bool) glfwSwapInterval(1) else glfwSwapInterval(0)

  def update(): Unit = glfwSwapBuffers(window)

  def isCloseRequested: Boolean = if (Input.isKeyPressed(GLFW_KEY_ESCAPE) || glfwWindowShouldClose(window) == GLFW_TRUE) true else false

  def close(): Unit = glfwDestroyWindow(window)

}
