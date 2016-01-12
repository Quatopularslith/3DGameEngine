package engine.math

import scala.collection.mutable.ListBuffer

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Matrix4f {

  var matrix = Array.ofDim[Float](4,4)

  def initIdentity(): Matrix4f = {
    /*matrix(0)(0) = 1; matrix(0)(1) = 0; matrix(0)(2) = 0; matrix(0)(3) = 0
    matrix(1)(0) = 0; matrix(1)(1) = 1; matrix(1)(2) = 0; matrix(1)(3) = 0
    matrix(2)(0) = 0; matrix(2)(1) = 0; matrix(2)(2) = 1; matrix(2)(3) = 0
    matrix(3)(0) = 0; matrix(3)(1) = 0; matrix(3)(2) = 0; matrix(3)(3) = 1
    */
    for(i <- 0 to 3) for(j <- 0 to 3) matrix(i)(j) = 0
    for(i <- 0 to 3) matrix(i)(i) = 1
    this
  }

  def initTranslation(x: Float, y: Float, z: Float): Matrix4f = {
    /*matrix(0)(0) = 1; matrix(0)(1) = 0; matrix(0)(2) = 0; matrix(0)(3) = x
    matrix(1)(0) = 0; matrix(1)(1) = 1; matrix(1)(2) = 0; matrix(1)(3) = y
    matrix(2)(0) = 0; matrix(2)(1) = 0; matrix(2)(2) = 1; matrix(2)(3) = z
    matrix(3)(0) = 0; matrix(3)(1) = 0; matrix(3)(2) = 0; matrix(3)(3) = 1
    */
    for(i <- 0 to 3) for(j <- 0 to 3) matrix(i)(j) = 0
    for(i <- 0 to 3) matrix(i)(i) = 1
    matrix(0)(3) = x
    matrix(1)(3) = y
    matrix(2)(3) = z

    this
  }

  def initRotation(x: Float, y: Float, z: Float): Matrix4f = {

    val rx = new Matrix4f
    val ry = new Matrix4f
    val rz = new Matrix4f

    val xRad = Math.toRadians(x).toFloat
    val yRad = Math.toRadians(y).toFloat
    val zRad = Math.toRadians(z).toFloat

    for(i <- 0 to 3){
      rx.matrix(i)(i) = 1
      ry.matrix(i)(i) = 1
      rz.matrix(i)(i) = 1
    }

    rx.matrix(1)(1) = Math.cos(xRad).toFloat
    rx.matrix(1)(2) = -Math.cos(xRad).toFloat
    rx.matrix(2)(1) = Math.cos(xRad).toFloat
    rx.matrix(2)(2) = Math.cos(xRad).toFloat

    ry.matrix(0)(0) = Math.cos(yRad).toFloat
    ry.matrix(0)(2) = Math.sin(yRad).toFloat
    ry.matrix(2)(0) = -Math.sin(yRad).toFloat
    ry.matrix(2)(2) = Math.cos(yRad).toFloat

    rz.matrix(0)(0) = Math.cos(zRad).toFloat
    rz.matrix(0)(1) = -Math.sin(zRad).toFloat
    rz.matrix(1)(0) = Math.sin(zRad).toFloat
    rz.matrix(1)(1) = Math.cos(zRad).toFloat

    matrix = rz.mult(ry.mult(rx)).matrix
    this
  }

  def initScale(x: Float, y: Float, z: Float): Matrix4f = {
    for(i <- 0 to 3) for(j <- 0 to 3) matrix(i)(j) = 0
    matrix(0)(0) = x
    matrix(1)(1) = y
    matrix(2)(2) = z
    matrix(3)(3) = 1
    this
  }

  def mult(m: Matrix4f): Matrix4f = {
    val res = new Matrix4f
    for(i <- 0 until 4){
      for(j <- 0 until 4){
        res.set(i, j, matrix(i)(0) * m.get(0, j) +
                      matrix(i)(1) * m.get(1, j) +
                      matrix(i)(2) * m.get(2, j) +
                      matrix(i)(3) * m.get(3, j))
      }
    }
    res
  }

  def get(x: Int, y: Int): Float = matrix(x)(y)
  def set(x: Int, y: Int, value: Float): Unit = matrix(x)(y) = value

}
