package engine.game

import engine.core.Time
import engine.input.Input
import engine.mesh.{Vertex, Mesh}
import engine.math.Vector3f
import engine.shader.Shader
import engine.transformation.Transformation
import engine.util.ResourceLoader
import org.lwjgl.glfw.GLFW._
/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Game {

  private val mesh = ResourceLoader.loadMesh("cube.obj", isStream = true)
  /*val vertices: Array[Vertex] = Array[Vertex] (new Vertex(new Vector3f(-1, -1, 0)),
                               new Vertex(new Vector3f(0, 1, 0)),
                               new Vertex(new Vector3f(1, -1, 0)),
                               new Vertex(new Vector3f(0,-1,1)))

  val indicies: Array[Int] = Array[Int] (0, 1, 3, 3, 1, 2, 2, 1, 0, 0, 2, 3)

  mesh.addVertices(vertices, indicies)*/

  private val transform = new Transformation

  private val shader = new Shader
  shader.addVertexShader(ResourceLoader.loadShader("basicVertex.glsl", isStream = true))
  shader.addFragmentShader(ResourceLoader.loadShader("basicFragment.glsl", isStream = true))
  shader.compileShader()

  shader.addUniform("transform")
  //shader.addUniform("uniformFloat")

  def input(): Unit ={

    if(Input.isKeyDown(GLFW_KEY_UP)) println("PRESSED UP")
    if(Input.isKeyReleased(GLFW_KEY_UP)) println("RELEASED UP")
    if(Input.isMButtonDown(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE DOWN")
    if(Input.isMButtonReleased(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE UP")

  }

  def render(): Unit ={
    shader.bind()
    shader.setUniformm("transform", transform.transformationMatrix)
    //shader.setUniformf("uniformFloat", uniformFloat)
    mesh.draw()
  }

  var delta: Float = 0.0f
  var uniformFloat: Float = 0.0f

  def update(): Unit ={
    delta += Time.delta.toFloat
    val sinDelta = Math.sin(delta)
    //uniformFloat = Math.abs(Math.sin(delta)).toFloat
    transform.translation = new Vector3f(sinDelta.toFloat, 0, 0)
    transform.rotation = new Vector3f(0, Math.sin(delta).toFloat * 90, sinDelta.toFloat * 180)
    transform.scale = new Vector3f((0.5 * sinDelta).toFloat, (0.5 * sinDelta).toFloat, (0.5 * sinDelta).toFloat)
    //transform.scale = new Vector3f(0.4.toFloat, 0.4.toFloat, 0.4.toFloat)
  }

}
