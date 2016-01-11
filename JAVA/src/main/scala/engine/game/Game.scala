package engine.game

import engine.input.Input
import engine.mesh.{Vertex, Mesh}
import engine.math.Vector3f
import engine.shader.{ResourceLoader, Shader}
import org.lwjgl.glfw.GLFW._
/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Game {

  private val mesh = new Mesh
  val data: Array[Vertex] = Array(new Vertex(new Vector3f(-1, -1, 0)),
                               new Vertex(new Vector3f(0, 1, 0)),
                               new Vertex(new Vector3f(1, -1, 0)))
  mesh.addVertices(data)

  private val shader = new Shader
  shader.addVertexShader(ResourceLoader.loadShader("basicVertex.glsl", isStream = true))
  shader.addFragmentShader(ResourceLoader.loadShader("basicFragment.glsl", isStream = true))
  shader.compileShader()

  def input(): Unit ={

    if(Input.isKeyDown(GLFW_KEY_UP)) println("PRESSED UP")
    if(Input.isKeyReleased(GLFW_KEY_UP)) println("RELEASED UP")
    if(Input.isMButtonDown(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE DOWN")
    if(Input.isMButtonReleased(GLFW_MOUSE_BUTTON_LEFT)) println("MOUSE UP")

  }

  def render(): Unit ={
    shader.bind()
    mesh.draw()
  }

  def update(): Unit ={

  }

}
