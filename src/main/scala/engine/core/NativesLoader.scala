package engine.core

import java.io.{FileOutputStream, File}
import java.nio.channels.Channels

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object NativesLoader {

  private def arch: String = {
    if(System.getProperty("os.arch").contains("64"))
      "64"
    else
      "32"
  }

  private def os: String = {
    val osName = System.getProperty("os.name").toLowerCase()
    if(osName.contains("win"))
      "win"
    else if(osName.contains("mac"))
      "mac"
    else
      "linux"
  }

  private val win32Dir = "engine/natives/win/32/"
  private val win32 = List(win32Dir + "glfw32.dll", win32Dir + "jemalloc32.dll", win32Dir + "lwjgl32.dll", win32Dir + "OpenAL32.dll")

  private val win64Dir = "engine/natives/win/64/"
  private val win64 = List(win64Dir + "glfw.dll", win64Dir + "jemalloc.dll", win64Dir + "lwjgl.dll", win64Dir + "OpenAL.dll")

  private val lin32Dir = "engine/natives/linux/32/"
  private val lin32 = List(win32Dir + "libglfw32.so", win32Dir + "libjemalloc32.so", win32Dir + "liblwjgl32.so", win32Dir + "libopenal32.so")

  private val lin64Dir = "engine/natives/linux/64/"
  private val lin64 = List(win64Dir + "libglfw.so", win64Dir + "libjemalloc.so", win64Dir + "liblwjgl.so", win64Dir + "libopenal.so")

  private val macDir = "engine/natives/mac/"
  private val mac = List(macDir + "libglfw.dylib", macDir + "libjemalloc.dylib", macDir + "liblwjgl.dylib", macDir + "libopenal.dylib")

  private val destDir = System.getProperty("java.io.tmpdir") + "/lwjglNatives"

  def load(): Unit ={

    os match {
      case "win" =>
        arch match {
          case "32" => win32.foreach(l => System.load(move(l)))
          case "64" => win64.foreach(l => System.load(move(l)))
        }
      case "linux" =>
        arch match {
          case "32" => lin32.foreach(l => System.load(move(l)))
          case "64" => lin64.foreach(l => System.load(move(l)))
        }
      case "mac" =>
        mac.foreach(l => System.load(move(l)))
    }

  }

  private def move(lib: String): String = {
    val source = Channels.newChannel(getClass.getResourceAsStream(""))
    val fileOut = new File(destDir, "")
    val dest = new FileOutputStream(fileOut)
    dest.getChannel.transferFrom(source, 0, Long.MaxValue)
    source.close()
    dest.close()

    sys.addShutdownHook(fileOut.delete())
    fileOut.getAbsolutePath
  }

}
