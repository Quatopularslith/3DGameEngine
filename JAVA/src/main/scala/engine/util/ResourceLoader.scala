package engine.util

import java.io.{InputStreamReader, BufferedReader, InputStream}

import engine.math.Vector3f
import engine.mesh.{Vertex, Mesh}

import scala.collection.mutable.ListBuffer
import scala.io.{BufferedSource, Source}

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object ResourceLoader {

  def loadShader(fileName: String, isStream: Boolean, path: String = "/engine/shaders/"): String = {
    if(isStream) {
      Source.fromInputStream(getClass.getResourceAsStream(path + fileName)).getLines().mkString("\n")
    }
    else
      Source.fromFile(path + fileName).getLines().mkString("\n")
  }

  def loadMesh(fileName: String, isStream: Boolean, path: String = "/engine/models/"): Mesh = {
    val vertices = new ListBuffer[Vertex]
    val indicies = new ListBuffer[Int]
    def removeEmptyStrings(data: Array[String]): Array[String] = {
      val res = new ListBuffer[String]
      data.foreach(d => if(!d.equals("")) res += d)
      res.toArray
    }

    def read(buffSource: Iterator[String]): Unit ={

      buffSource.foreach{ l =>
        val tokens = l.split(" ")

        if(tokens(0).equals("v")) vertices += new Vertex(new Vector3f(tokens(1).toFloat,
                                                                      tokens(2).toFloat,
                                                                      tokens(3).toFloat))
        else if(tokens(0).equals("f")){
          indicies += tokens(1).toInt - 1
          indicies += tokens(2).toInt - 1
          indicies += tokens(3).toInt -  1
        }
      }

    }

    if(isStream)
      read(Source.fromInputStream(getClass.getResourceAsStream(path + fileName)).getLines())
    else
      read(Source.fromFile(path + fileName).getLines())

    val res = new Mesh
    res.addVertices(vertices.toArray, indicies.toArray)
    res
  }

}
