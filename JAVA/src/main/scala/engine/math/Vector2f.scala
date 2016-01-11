package engine.math

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */

class Vector2f(x1: Float, y1: Float) {

  var x: Float = x1
  var y: Float = y1
  def string(): String = "(x: " + x + ", y: " + y + ")"

  def length(): Float = Math.sqrt(x * x + y * y).toFloat
  def dot(v: Vector2f): Float = x * v.x + y * v.y

  def normalize(): Vector2f = {
    val l = length
    x /= l
    y /= l
    this
  }

  def rotate(angle: Float): Vector2f = {
    val radians: Double = Math.toRadians(angle)
    val cos: Double = Math.cos(radians)
    val sin: Double = Math.sin(radians)
    new Vector2f((x * cos - y * sin).toFloat, (x * sin + y * cos).toFloat)
  }

  def add(v: Vector2f): Vector2f = {
    new Vector2f(x + v.x, y + v.y)
  }

  def add(v: Float): Vector2f = {
    new Vector2f(x + v, y + v)
  }

  def sub(v: Vector2f): Vector2f = {
    new Vector2f(x - v.x, y - v.y)
  }

  def sub(v: Float): Vector2f = {
    new Vector2f(x - v, y - v)
  }

  def mult(v: Vector2f): Vector2f = {
    new Vector2f(x * v.x, y * v.y)
  }

  def mult(v: Float): Vector2f = {
    new Vector2f(x * v, y * v)
  }

  def div(v: Vector2f): Vector2f = {
    new Vector2f(x / v.x, y / v.y)
  }

  def div(v: Float): Vector2f = {
    new Vector2f(x / v, y / v)
  }

}
