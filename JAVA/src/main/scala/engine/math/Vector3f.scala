package engine.math

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Vector3f(x1: Float, y1: Float, z1: Float) {

  var x: Float = x1
  var y: Float = y1
  var z: Float = z1

  def string(): String = "(x: " + x + ", y: " + y + ", z: " + z +  ")"
  def length(): Float = Math.sqrt(x * x + y * y + z * z).toFloat
  def dot(v: Vector3f): Float = x * v.x + y * v.y + z * v.z

  def normalize(): Vector3f = {
    val l = length()
    x /= l
    y /= l
    z /= l
    this
  }

  //def rotate(angle: Float): Vector3f = {
  //
  //}

  def add(v: Vector3f): Vector3f = {
    new Vector3f(x + v.x, y + v.y, z + v.z)
  }

  def add(v: Float): Vector3f = {
    new Vector3f(x + v, y + v, z + v)
  }

  def sub(v: Vector3f): Vector3f = {
    new Vector3f(x - v.x, y - v.y, z - v.z)
  }

  def sub(v: Float): Vector3f = {
    new Vector3f(x - v, y - v, z - v)
  }

  def mult(v: Vector3f): Vector3f = {
    new Vector3f(x * v.x, y * v.y, z * v.z)
  }

  def mult(v: Float): Vector3f = {
    new Vector3f(x * v, y * v, z * v)
  }

  def div(v: Vector3f): Vector3f = {
    new Vector3f(x / v.x, y / v.y, z / v.z)
  }

  def div(v: Float): Vector3f = {
    new Vector3f(x / v, y / v, z / v)
  }

}
