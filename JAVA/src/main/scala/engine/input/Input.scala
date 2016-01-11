package engine.input

import engine.window.Window
import org.lwjgl.BufferUtils
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.{GLFWMouseButtonCallback, GLFWKeyCallback}

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

object Input {

  object States extends Enumeration {
    type States = Value
    val Idle, Release, Press, Repeat = Value
  }

  val keyState: Array[States.States] = new Array[States.States](GLFW_KEY_LAST)
  val mButtonState: Array[States.States] = new Array[States.States](GLFW_MOUSE_BUTTON_LAST)

  def resetStates(): Unit = {
    for (i <- 0 until keyState.length) keyState(i) = States.Idle
    for (i <- 0 until mButtonState.length) mButtonState(i) = States.Idle
  }

  //Key Buttons

  def isKeyDown(keyCode: Int): Boolean = keyState(keyCode) == States.Press

  def isKeyPressed(keyCode: Int): Boolean = keyState(keyCode) == States.Press || keyState(keyCode) == States.Repeat

  def isKeyRepeated(keyCode: Int): Boolean = keyState(keyCode) == States.Repeat

  def isKeyReleased(keyCode: Int): Boolean = keyState(keyCode) == States.Release

  object KeyCallback extends GLFWKeyCallback {
    @Override
    def invoke(window: Long, key: Int, scancode: Int, action: Int, mods: Int): Unit = {
      action match {
        case GLFW_RELEASE => keyState(key) = States.Release
        case GLFW_PRESS => keyState(key) = States.Press
        case GLFW_REPEAT => keyState(key) = States.Repeat
      }
    }
  }

  //Mouse Inputs

  def isMButtonDown(mButtonCode: Int): Boolean = mButtonState(mButtonCode) == States.Press
  def isMButtonReleased(mButtonCode: Int): Boolean = mButtonState(mButtonCode) == States.Release
  def isMButtonPressed(mButtonCode: Int): Boolean = mButtonState(mButtonCode) == States.Press || mButtonState(mButtonCode) == States.Repeat
  def isMButtonRepeated(mButtonCode: Int): Boolean = mButtonState(mButtonCode) == States.Release

  object MButtonCallback extends GLFWMouseButtonCallback {
    @Override
    def invoke(window: Long, key: Int, action: Int, mods: Int): Unit = {
      action match {
        case GLFW_RELEASE => mButtonState(key) = States.Release
        case GLFW_PRESS => mButtonState(key) = States.Press
        case GLFW_REPEAT => mButtonState(key) = States.Repeat
      }
    }
  }

  //Mouse Cursor

  def cursorPos(): Tuple2[Double, Double] = {
    val coords = BufferUtils.createDoubleBuffer(2)
    glfwGetCursorPos(Window.window, coords, coords)
    (coords.get(0), coords.get(1))
  }

}