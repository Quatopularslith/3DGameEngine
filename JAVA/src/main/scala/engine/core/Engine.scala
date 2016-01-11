package engine.core

import engine.game.Game
import engine.input.Input
import engine.util.RenderUtil
import engine.window.Window
import org.lwjgl.glfw.GLFW._
import org.lwjgl.glfw.GLFWErrorCallback
import org.lwjgl.opengl.GL

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Engine {

  private var running = false
  private val FPS_CAP = 60

  private lazy val game = new Game

  def start(): Unit = {

    //Go to run method if engine is not running
    if (running) None
    else run()

  }

  def stop(): Unit = {

    //If running isn't already false, set it to false
    if (!running) None
    else running = false

  }

  private def run(): Unit = {

    //Set running to true
    running = true
    init()

    //Create window
    Window.createWindow(1280, 720, "3D Engine")
    Window.makeCurrentContext()
    Window.centerWindow()
    Window.showWindow()

    glfwSetKeyCallback(Window.window, Input.KeyCallback)
    glfwSetMouseButtonCallback(Window.window, Input.MButtonCallback)

    GL.createCapabilities()
    RenderUtil.initGraphics()
    println(RenderUtil.openGLVersion)

    loop()
  }

  private def loop(): Unit = {

    Window.vsync(false)

    //Variables for fps counter
    var frames: Int = 0
    var frameCounter: Long = 0
    val frameTime: Double = 1.0 / FPS_CAP
    var lastTime: Long = Time.getTime
    var unprocessedTime: Double = 0

    //Main loop
    while (running) {

      //Should the window render new content
      var shouldRender = false


      val startTime: Long = Time.getTime
      val passedTime: Long = startTime - lastTime
      lastTime = startTime
      unprocessedTime += passedTime / Time.second.asInstanceOf[Double]
      frameCounter += passedTime

      //Make sure everything stays in sync
      while (unprocessedTime > frameTime) {
        Input.resetStates()
        glfwPollEvents()

        shouldRender = true
        unprocessedTime -= frameTime
        if (Window.isCloseRequested) stop()

        Time.setDelta(frameTime)

        //Update Game
        game.input()
        game.update()

        //Print frames and reset counter
        if (frameCounter >= Time.second) {
          Window.setTitle("3DGameEngine -- FPS: " + frames)
          frames = 0
          frameCounter = 0
        }

      }

      //If everything is in sync, the window should render new updates, otherwise sleep and wait to catch up
      if (shouldRender) {
        render()
        frames += 1
      } else Thread.sleep(1)

    }

    cleanUp()

  }

  private def render(): Unit = {
    Window.update()
    game.render()
  }

  private def cleanUp(): Unit = {
    Window.close()
    glfwTerminate()
    NativesLoader.delete()
  }

  private def init(): Unit = {

    glfwSetErrorCallback(GLFWErrorCallback.createPrint(System.err))

    if (glfwInit() != GLFW_TRUE) {
      println("GLFW failed to init")
      sys.exit()
    }

  }

}
