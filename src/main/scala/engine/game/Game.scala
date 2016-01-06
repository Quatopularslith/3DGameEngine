package engine.game

import engine.input.Input
import org.lwjgl.glfw.GLFW._
/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Game {

  def input(): Unit ={

    if(Input.isKeyDown(GLFW_KEY_UP)) println("PRESSED UP")
    if(Input.isKeyUp(GLFW_KEY_UP)) println("RELEASED UP")
    if(Input.isMButtonDown(GLFW_MOUSE_BUTTON_1)) println("MOUSE DOWN")
    if(Input.isMButtonUp(GLFW_MOUSE_BUTTON_1)) println("MOUSE UP")

  }

  def render(): Unit ={

  }

  def update(): Unit ={

  }

}
