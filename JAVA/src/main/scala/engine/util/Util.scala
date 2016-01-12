package engine.util

import java.nio.{IntBuffer, FloatBuffer}

import engine.math.Matrix4f
import engine.mesh.Vertex
import org.lwjgl.BufferUtils

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Util {

  def createFlippedBuffer(vertices: Array[Vertex]): FloatBuffer = {
    val buffer = BufferUtils.createFloatBuffer(vertices.length * Vertex.SIZE)

    for(i <- 0 until vertices.length){
      buffer.put(vertices(i).pos.x)
      buffer.put(vertices(i).pos.y)
      buffer.put(vertices(i).pos.z)
    }

    buffer.flip()
    buffer
  }

  def createFlippedBuffer(value: Matrix4f): FloatBuffer = {
    val buffer = BufferUtils.createFloatBuffer(16)

    for(i <- 0 until 4) for (j <- 0 until 4) buffer.put(value.get(i, j))
    buffer.flip()
    buffer
  }

  def createFlippedBuffer(values: Array[Int]): IntBuffer ={
    val buffer = BufferUtils.createIntBuffer(values.length)
    buffer.put(values)
    buffer.flip()
    buffer
  }

}
