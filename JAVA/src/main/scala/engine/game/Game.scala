package engine.game

import engine.core.Time
import engine.input.Input
import engine.mesh.{Vertex, Mesh}
import engine.math.Vector3f
import engine.shader.{ResourceLoader, Shader}
import engine.transformation.Transformation
import org.lwjgl.glfw.GLFW._
/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Game {

  private val mesh = new Mesh
  val data: Array[Vertex] = Array[Vertex] (new Vertex(new Vector3f(-1, -1, 0)),
                               new Vertex(new Vector3f(0, 1, 0)),
                               new Vertex(new Vector3f(1, -1, 0)))

  mesh.addVertices(data)

  private val transform = new Transformation

  private val shader = new Shader
  shader.addVertexShader(ResourceLoader.loadShader("basicVertex.glsl", isStream = true))
  shader.addFragmentShader(ResourceLoader.loadShader("basicFragment.glsl", isStream = true))
  shader.compileShader()

  shader.addUniform("transform")
  shader.addUniform("uniformFloat")

  def input(): Unit ={

    if(Input.isKeyDown(GLFW_KEY_UP)) println("PRESSED UP")
    if(Input.isKeyReleased(GLFW_KEY_UP)) println("RELEASED UP")
    if(Input.isMButtonDown(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE DOWN")
    if(Input.isMButtonReleased(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE UP")

  }

  def render(): Unit ={
    shader.bind()
    shader.setUniformm("transform", transform.transformationMatrix)
    shader.setUniformf("uniformFloat", tempAmount)
    mesh.draw()
  }

  var temp: Float = 0.0f
  var tempAmount: Float = 0.0f

  def update(): Unit ={
    temp += Time.delta.toFloat
    tempAmount = Math.abs(Math.sin(temp)).toFloat
    transform.translation = new Vector3f(Math.sin(temp).toFloat, 0, 0)
  }

}
