//
// Created by Razim on 3/2/2016.
//

#include <iostream>
#include "Shader.h"
#include "../../glew/glew.h"
#include "../util/Util.h"

Shader::Shader() {
    program = glCreateProgram();
}

void Shader::bind() {
    glUseProgram(program);
}

void Shader::addUniform(const GLchar* uniform) {
    GLint uniformLocation = glGetUniformLocation(program, uniform);
    if(uniformLocation == -1) std::cout << "Error: Could not find uniform: " << std::endl;
    uniforms[uniform] = uniformLocation;
}

void Shader::addVertexShader(const GLchar** source) {
    addProgram(source, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(const GLchar** source) {
    addProgram(source, GL_FRAGMENT_SHADER);
}

void Shader::addGeoShader(const GLchar** source) {
    addProgram(source, GL_GEOMETRY_SHADER);
}

void Shader::compileShader() {
    glLinkProgram(program);
    GLint link;
    GLint validate;
    glGetProgramiv(program, GL_LINK_STATUS, &link);
    glGetProgramiv(program, GL_VALIDATE_STATUS, &validate);

    if(link == 0 || validate == 0){
        GLchar infoLog;
        glGetShaderInfoLog(program, 1024, NULL, &infoLog);
    }


}

void Shader::addProgram(const GLchar** source, GLenum pType) {
    GLuint shader = glCreateShader(pType);
    if(shader == 0) std::cout << "Shader creation failed: Could not find valid memory location when adding shader" << std::endl;
    glShaderSource(shader, NULL, source, NULL);
    glCompileShader(shader);
    GLint returns;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &returns);
    if(returns == 0) {
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
    glUniform4fv(uniforms[uniformName], sizeof(value), Util::createFlippedBuffer(value));
}
