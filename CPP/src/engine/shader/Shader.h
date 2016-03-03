//
// Created by Razim on 3/2/2016.
//

#ifndef INC_3DGAMEENGINE_SHADER_H
#define INC_3DGAMEENGINE_SHADER_H


#include <map>
#include <string>
#include "../../glew/glew.h"
#include "../math/Vector3f.h"
#include "../math/Matrix4f.h"

class Shader {
public:
    Shader();
    void bind();
    void addUniform(const GLchar* uniform);
    void addVertexShader(const GLchar** source);
    void addFragmentShader(const GLchar** source);
    void addGeoShader(const GLchar** source);
    void compileShader();

    void setUniformi(std::string uniformName, GLint value);
    void setUniformf(std::string uniformName, GLfloat value);
    void setUniformv(std::string uniformName, Vector3f value);
    void setUniformm(std::string uniformName, Matrix4f value);
private:
    GLuint program;
    std::map<std::string, int> uniforms;
    void addProgram(const GLchar** source, GLenum pType);
};


#endif //INC_3DGAMEENGINE_SHADER_H
