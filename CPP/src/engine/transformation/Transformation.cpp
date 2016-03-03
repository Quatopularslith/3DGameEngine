//
// Created by Razim on 3/2/2016.
//

#include "Transformation.h"

Transformation::Transformation() : translation(Vector3f(0, 0, 0)), rotation(Vector3f(0, 0, 0)), scale(Vector3f(1,1,1)){ }

Matrix4f Transformation::transformationmatrix() {
    printf("b1\n");

    Matrix4f translationMatrix = Matrix4f().initTranslation(translation.getX(), translation.getY(), translation.getZ());
    printf("b2\n");

    Matrix4f rotationMatrix = Matrix4f().initRotation(rotation.getX(), rotation.getY(), rotation.getZ());
    printf("b3\n");

    Matrix4f scaleMatrix = Matrix4f().initScale(scale.getX(), scale.getY(), scale.getZ());
    return translationMatrix.mult(rotationMatrix.mult(scaleMatrix));
}
