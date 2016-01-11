package engine.util

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

import org.lwjgl.opengl.GL11._
import org.lwjgl.opengl.GL30.GL_FRAMEBUFFER_SRGB

object RenderUtil {

  def clearScreen(): Unit = {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
  }

  def initGraphics(): Unit = {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f)

    glFrontFace(GL_CW)
    glCullFace(GL_BACK)
    glEnable(GL_CULL_FACE)
    glEnable(GL_DEPTH_TEST)

    glEnable(GL_FRAMEBUFFER_SRGB)
  }

  def openGLVersion: String = glGetString(GL_VERSION)

}
