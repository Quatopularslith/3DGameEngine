package engine.shader

import java.io.{File, FileReader, BufferedReader, InputStreamReader}

import scala.io.Source

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
      Source.fromFile(path + fileName).getLines().mkString
  }

}
