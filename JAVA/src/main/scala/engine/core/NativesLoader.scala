package engine.core

import java.io.{File, FileOutputStream}
import java.nio.channels.Channels
import java.nio.file.{Files, Paths}

import scala.collection.mutable.ListBuffer

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object NativesLoader {

  private def arch: String = {
    if (System.getProperty("os.arch").contains("64"))
      "64"
    else
      "32"
  }

  private def os: String = {
    val osName = System.getProperty("os.name").toLowerCase()
    if (osName.contains("win"))
      "win"
    else if (osName.contains("mac"))
      "mac"
    else
      "linux"
  }

  private val win32Dir = "engine/natives/win/32/"
  private val win32 = List(win32Dir + "glfw32.dll", win32Dir + "jemalloc32.dll", win32Dir + "lwjgl32.dll", win32Dir + "OpenAL32.dll")

  private val win64Dir = "engine/natives/win/64/"
  private val win64 = List(win64Dir + "glfw.dll", win64Dir + "jemalloc.dll", win64Dir + "lwjgl.dll", win64Dir + "OpenAL.dll")

  private val lin32Dir = "engine/natives/linux/32/"
  private val lin32 = List(lin32Dir + "libglfw32.so", lin32Dir + "libjemalloc32.so", lin32Dir + "liblwjgl32.so", lin32Dir + "libopenal32.so")

  private val lin64Dir = "engine/natives/linux/64/"
  private val lin64 = List(lin64Dir + "libglfw.so", lin64Dir + "libjemalloc.so", lin64Dir + "liblwjgl.so", lin64Dir + "libopenal.so")

  private val macDir = "engine/natives/mac/"
  private val mac = List(macDir + "libglfw.dylib", macDir + "libjemalloc.dylib", macDir + "liblwjgl.dylib", macDir + "libopenal.dylib")

  def load(): Unit = {

    if (!Files.isDirectory(Paths.get(destDir))) Files.createDirectory(Paths.get(destDir))

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

    System.setProperty("org.lwjgl.librarypath", destDir)

  }

  private val destDir = Paths.get("").toAbsolutePath.toString + "/natives/"
  private def move(lib: String): String = {
    val source = Channels.newChannel(NativesLoader.getClass.getClassLoader.getResourceAsStream(lib))
    val fileOut = new File(destDir, lib.split('/').last)
    val dest = new FileOutputStream(fileOut)
    dest.getChannel.transferFrom(source, 0, Long.MaxValue)
    source.close()
    dest.close()

    println(lib.split('/').last + " loaded")
    fileOut.getAbsolutePath
  }

}
