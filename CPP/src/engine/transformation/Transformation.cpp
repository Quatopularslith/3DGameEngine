//
// Created by Razim on 3/2/2016.
//

#include "Transformation.h"

Vector3f translation = Vector3f(0, 0, 0);
Vector3f rotation = Vector3f(0, 0, 0);
Vector3f scale = Vector3f(1, 1, 1);

Matrix4f Transformation::transformationmatrix() {
    Matrix4f translationMatrix = Matrix4f().initTranslation(translation.getX(), translation.getY(), translation.getZ());
    Matrix4f rotationMatrix = Matrix4f().initRotation(rotation.getX(), rotation.getY(), rotation.getZ());
    Matrix4f scaleMatrix = Matrix4f().initScale(scale.getX(), scale.getY(), scale.getZ());
    return translationMatrix.mult(rotationMatrix.mult(scaleMatrix));
}
