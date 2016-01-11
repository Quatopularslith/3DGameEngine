package engine.mesh

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

import engine.util.Util
import org.lwjgl.opengl.GL11._
import org.lwjgl.opengl.GL15._
import org.lwjgl.opengl.GL20._

class Mesh {

  private val vbo: Int = glGenBuffers
  private var size: Int = _

  def addVertices(vertices: Array[Vertex]): Unit = {
    size = vertices.length

    glBindBuffer(GL_ARRAY_BUFFER, vbo)
    glBufferData(GL_ARRAY_BUFFER, Util.createFlippedBuffer(vertices), GL_STATIC_DRAW)
  }

  def draw(): Unit ={
    glEnableVertexAttribArray(0)
    glBindBuffer(GL_ARRAY_BUFFER, vbo)
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex.SIZE * 4, 0)
    glDrawArrays(GL_TRIANGLES, 0, size)
    glDisableVertexAttribArray(0)
  }

}
