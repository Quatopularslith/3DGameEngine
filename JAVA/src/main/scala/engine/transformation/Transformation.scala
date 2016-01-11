package engine.transformation

import engine.math.{Matrix4f, Vector3f}

/**
  * Created by Mnenmenth Alkaborin
  * Please refer to LICENSE file if included
  * for licensing information
  * https://github.com/Mnenmenth
  */
class Transformation {

  var translation: Vector3f = new Vector3f(0, 0, 0)
  var rotation: Vector3f = new Vector3f(0, 0, 0)

  def transformationMatrix: Matrix4f = {
    val translationMatrix = new Matrix4f().initTranslation(translation.x, translation.y, translation.z)
    val rotationMatrix = new Matrix4f()

    translationMatrix
  }

}
