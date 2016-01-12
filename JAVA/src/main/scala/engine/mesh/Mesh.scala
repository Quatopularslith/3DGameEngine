package engine.mesh

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

import java.io.{InputStreamReader, InputStream, File}

import engine.util.Util
import org.lwjgl.opengl.GL11._
import org.lwjgl.opengl.GL15._
import org.lwjgl.opengl.GL20._

class Mesh {

  private lazy val vbo: Int = glGenBuffers
  private lazy val ibo: Int = glGenBuffers
  private var size: Int = _

  def addVertices(vertices: Array[Vertex], indices: Array[Int]): Unit = {
    size = indices.length

    glBindBuffer(GL_ARRAY_BUFFER, vbo)
    glBufferData(GL_ARRAY_BUFFER, Util.createFlippedBuffer(vertices), GL_STATIC_DRAW)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, Util.createFlippedBuffer(indices), GL_STATIC_DRAW)
  }

  def draw(): Unit ={
    glEnableVertexAttribArray(0)
    glBindBuffer(GL_ARRAY_BUFFER, vbo)
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex.SIZE * 4, 0)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo)
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0)

    glDisableVertexAttribArray(0)
  }

}
