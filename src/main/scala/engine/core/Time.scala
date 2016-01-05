package engine.core

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
object Time {

  val second: Long = 1000000000

  def getTime = System.nanoTime()

  var delta: Double = 0

  def setDelta(delta: Double) = Time.delta = delta

}
