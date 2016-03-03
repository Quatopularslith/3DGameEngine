//
// Created by Razim on 3/2/2016.
//

#include <iostream>
#include "Shader.h"
#include "../util/Util.h"
#define GLEW_STATIC
#include "../../glew/glew.h"


Shader::Shader() : program(glCreateProgram()){ }

void Shader::bind() {
    glUseProgram(program);
}

void Shader::addUniform(const char *uniform) {
    GLint uniformLocation = glGetUniformLocation(program, uniform);
    if (uniformLocation == -1) std::cout << "Error: Could not find uniform: "  << uniform << std::endl;
    uniforms[uniform] = uniformLocation;
}

void Shader::addVertexShader(const char *source) {
    addProgram(source, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(const char *source) {
    addProgram(source, GL_FRAGMENT_SHADER);
}

void Shader::addGeoShader(const char *source) {
    addProgram(source, GL_GEOMETRY_SHADER);
}

void Shader::compileShader() {
    glLinkProgram(program);
    GLint link;
    glGetProgramiv(program, GL_LINK_STATUS, &link);

    if (link == 0) {
        GLchar infoLog;
        glGetShaderInfoLog(program, 1024, NULL, &infoLog);
        std::cout << infoLog << std::endl;
    }

    glValidateProgram(program);
    GLint validate;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &validate);

    if (validate == 0) {
        GLchar infoLog;
        glGetShaderInfoLog(program, 1024, NULL, &infoLog);
        std::cout << infoLog << std::endl;
    }

}

void Shader::addProgram(const char *source, GLenum pType) {
    GLuint shader = glCreateShader(pType);
    if (shader == 0)
        std::cout << "Shader creation failed: Could not find valid memory location when adding shader" << std::endl;
    std::string length = source;
    GLint lengths[1];
    lengths[0] = length.length();
    glShaderSource(shader, 1, &source, lengths);
    glCompileShader(shader);
    GLint returns;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &returns);
    if (returns == 0) {
        GLchar infoLog;
        glGetShaderInfoLog(shader, 1024, NULL, &infoLog);
    }
    glAttachShader(program, shader);
}

void Shader::setUniformi(std::string uniformName, GLint value) {
    glUniform1i(uniforms[uniformName], value);
}

void Shader::setUniformf(std::string uniformName, GLfloat value) {
    glUniform1f(uniforms[uniformName], value);
}

void Shader::setUniformv(std::string uniformName, Vector3f value) {
    glUniform3f(uniforms[uniformName], value.getX(), value.getY(), value.getZ());
}

void Shader::setUniformm(std::string uniformName, Matrix4f value) {
    printf("b\n");

    glUniform4fv(uniforms[uniformName], sizeof(value), Util::createFlippedBuffer(value));
    printf("e\n");

}
