package engine.math

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Quaternion(x1: Float, y1: Float, z1: Float, w1: Float) {

  var x: Float = x1
  var y: Float = y1
  var z: Float = z1
  var w: Float = w1

  def length(): Float = Math.sqrt(x * x + y * y + z * z + w * w).toFloat
  def conjugate(): Quaternion = new Quaternion(-x, -y, -z, w)

  def normalize(): Quaternion = {
    val l: Float = length
    x /= l
    y /= l
    z /= l
    w /= l
    this
  }

  def mult(q: Quaternion): Quaternion = {
    val w2: Float = w * q.w - x * q.x - y * q.y - z * q.z
    val x2: Float = x * q.w + w * q.x + y * q.z - z * q.y
    val y2: Float = y * q.w + w * q.y + z * q.x - x * q.z
    val z2: Float = z * q.w + w * q.z + x * q.y - y * q.z
    new Quaternion(x2, y2, z2, w2)
  }

  def mult(v: Vector3f): Quaternion = {
    val w2: Float = -x * v.x - y * v.y - z * v.z
    val x2: Float = w * v.x + y * v.z - z * v.y
    val y2: Float = w * v.y + z * v.x - x * v.z
    val z2: Float = w * v.z + x * v.y - y * v.x
    new Quaternion(x2, y2, z2, w2)
  }

}
