package engine.input

import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWKeyCallback

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object KeyHandler extends GLFWKeyCallback{

  object States extends Enumeration{
    type States = Value
    val Idle, Release, Press, Repeat = Value
  }

  val keyState: Array[States.States] = new Array[States.States](GLFW_KEY_LAST)

  def resetKeyStates(): Unit ={
    for(i <- 0 to keyState.length-1){
      keyState(i) = States.Idle
    }
  }

  def isKeyDown(keyCode: Int): Boolean = if(keyState(keyCode) == States.Press || keyState(keyCode) == States.Repeat) true else false

  def isKeyPressed(keyCode: Int): Boolean = if(keyState(keyCode) == States.Press) true else false

  def isKeyRepeated(keyCode: Int): Boolean = if(keyState(keyCode) == States.Repeat) true else false

  def isKeyReleased(keyCode: Int): Boolean = if(keyState(keyCode) == States.Release) true else false

  @Override
  def invoke(window: Long, key: Int, scancode: Int, action: Int, mods: Int): Unit = {
    action match {
      case GLFW_RELEASE => keyState(key) = States.Release
      case GLFW_PRESS => keyState(key) = States.Press
      case GLFW_REPEAT => keyState(key) = States.Repeat
    }
  }

}
