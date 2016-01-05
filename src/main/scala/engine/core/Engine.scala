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
  private val F_CAP = 60

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

    var render = false
    val frameTime = 1 / F_CAP
    var lastTime = Time.getTime
    var unprocessedTime: Double = 0

    while (running) {
      Window.update()

      var frames = 0
      var frameCounter: Long = 0

      val startTime = Time.getTime
      val passedTime = startTime - lastTime
      lastTime = startTime

      unprocessedTime += passedTime / Time.second
      frameCounter += passedTime

      while(unprocessedTime > frameTime){
        render = true
        unprocessedTime -= frameTime
        if(Window.isCloseRequested) stop()

        if(frameCounter >= Time.second) {
          println(frames)
          frames = 0
          frameCounter = 0
        }

      }

      KeyInput.input()

      if(render){
        render
        frames += 1
      } else Thread.sleep(1)

      KeyHandler.resetKeyStates()
      glfwPollEvents()
    }

    cleanUp()

  }

  private def render(): Unit ={

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
