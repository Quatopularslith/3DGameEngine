package engine.shader

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

import org.lwjgl.opengl.GL20._
import org.lwjgl.opengl.GL32._

class Shader {

  private val program: Int = glCreateProgram()

  if(program == 0) println("Shader creation failed: Could not find valid memory location in constructor")

  def bind(): Unit ={
    glUseProgram(program)
  }

  def addVertexShader(text: String): Unit ={
    addProgram(text, GL_VERTEX_SHADER)
  }

  def addFragmentShader(text: String): Unit ={
    addProgram(text, GL_FRAGMENT_SHADER)
  }

  def addGeoShader(text: String): Unit ={
    addProgram(text, GL_GEOMETRY_SHADER)
  }

  def compileShader(): Unit ={
    glLinkProgram(program)
    if(glGetProgrami(program, GL_LINK_STATUS) == 0) println(glGetShaderInfoLog(program, 1024))

    glValidateProgram(program)
    if(glGetProgrami(program, GL_VALIDATE_STATUS) == 0) println(glGetShaderInfoLog(program, 1024))
  }

  private def addProgram(text: String, pType: Int): Unit ={
    val shader = glCreateShader(pType)

    if(shader == 0) println("Shader creation failed: Could not find valid memory location when adding shader")

    glShaderSource(shader, text)
    glCompileShader(shader)

    if(glGetShaderi(shader, GL_COMPILE_STATUS) == 0) println(glGetShaderInfoLog(shader, 1024))

    glAttachShader(program, shader)

  }

}
