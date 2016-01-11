package engine.shader

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

import engine.math.{Matrix4f, Vector3f}
import engine.util.Util
import org.lwjgl.opengl.GL20._
import org.lwjgl.opengl.GL32._

import scala.collection.mutable

class Shader {

  private val program: Int = glCreateProgram()
  private val uniforms = new mutable.HashMap[String, Int]()

  if(program == 0) println("Shader creation failed: Could not find valid memory location in constructor")

  def bind(): Unit ={
    glUseProgram(program)
  }

  def addUniform(uniform: String): Unit ={
    val uniformLocation = glGetUniformLocation(program, uniform)

    if(uniformLocation == -1) println("Error: Could not find uniform: " + uniform)

    uniforms.put(uniform, uniformLocation)
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

  def setUniformi(uniformName: String, value: Int): Unit = glUniform1i(uniforms.getOrElse(uniformName,0), value)
  def setUniformf(uniformName: String, value: Float): Unit = glUniform1f(uniforms.getOrElse(uniformName,0), value)
  def setUniformv(uniformName: String, value: Vector3f): Unit = glUniform3f(uniforms.getOrElse(uniformName,0), value.x, value.y, value.z)
  def setUniformm(uniformName: String, value: Matrix4f): Unit = glUniformMatrix4fv(uniforms.getOrElse(uniformName,0), true, Util.createFlippedBuffer(value))

}
