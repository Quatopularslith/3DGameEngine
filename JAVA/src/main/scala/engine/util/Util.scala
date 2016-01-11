package engine.util

import java.nio.FloatBuffer

import engine.mesh.Vertex
import org.lwjgl.BufferUtils

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Util {

  def createFloatBuffer(size: Int): FloatBuffer ={
    BufferUtils.createFloatBuffer(size)
  }

  def createFlippedBuffer(vertices: Array[Vertex]): FloatBuffer ={
    val buffer = createFloatBuffer(vertices.length * Vertex.SIZE)

    for(i <- 0 until vertices.length){
      buffer.put(vertices(i).pos.x)
      buffer.put(vertices(i).pos.y)
      buffer.put(vertices(i).pos.z)
    }

    buffer.flip()
    buffer
  }

}
