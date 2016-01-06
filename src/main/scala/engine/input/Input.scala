package engine.input

import engine.window.Window

import scala.collection.mutable.ListBuffer
import org.lwjgl.glfw.GLFW._

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Input {

  //Number of keys that may be input
  val NUM_KEYCODES = 256
  val NUM_MBUTTONS = 4

  private val currentKeys: ListBuffer[Int] = new ListBuffer[Int]
  private val downKeys: ListBuffer[Int] = new ListBuffer[Int]
  private val upKeys: ListBuffer[Int] = new ListBuffer[Int]

  private val currentMButtons: ListBuffer[Int] = new ListBuffer[Int]
  private val mButtonDown: ListBuffer[Int] = new ListBuffer[Int]
  private val mButtonUp: ListBuffer[Int] = new ListBuffer[Int]


  def update(): Unit ={

    upKeys.clear()
    for(i <- 0 until NUM_KEYCODES) if(!isKeyPressed(i) && currentKeys.contains(i)) upKeys += i

    downKeys.clear()
    for(i <- 0 until NUM_KEYCODES) if(isKeyPressed(i) && !currentKeys.contains(i)) downKeys += i

    currentKeys.clear()
    for(i <- 0 until NUM_KEYCODES)if(isKeyPressed(i)) currentKeys += i

    mButtonUp.clear()
    for(i <- 0 until NUM_MBUTTONS) if(!isMButtonPressed(i) && currentMButtons.contains(i)) mButtonUp += i

    mButtonDown.clear()
    for(i <- 0 until NUM_MBUTTONS) if(isMButtonPressed(i) && !currentMButtons.contains(i)) mButtonDown += i

    currentMButtons.clear()
    for(i <- 0 until NUM_MBUTTONS) if(isMButtonPressed(i)) currentMButtons += i

  }

  //Keyboard methods
  def isKeyPressed(keyCode: Int): Boolean = if(glfwGetKey(Window.window, keyCode) == GLFW_PRESS) true else false

  def isKeyDown(keyCode: Int): Boolean = downKeys.contains(keyCode)

  def isKeyUp(keyCode: Int): Boolean = upKeys.contains(keyCode)

  //Mouse methods

  def isMButtonPressed(mButton: Int): Boolean = if(glfwGetMouseButton(Window.window, mButton) == GLFW_PRESS) true else false

  def isMButtonDown(mButton: Int): Boolean = mButtonDown.contains(mButton)

  def isMButtonUp(mButton: Int): Boolean = mButtonUp.contains(mButton)

}
