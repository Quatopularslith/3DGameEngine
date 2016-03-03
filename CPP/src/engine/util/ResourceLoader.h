//
// Created by Razim on 3/2/2016.
//

#ifndef INC_3DGAMEENGINE_RESOURCELOADER_H
#define INC_3DGAMEENGINE_RESOURCELOADER_H


#include <string>
#include "../mesh/Mesh.h"

class ResourceLoader {
public:
    static const GLchar** loadShader(std::string fileName, std::string path = "/engine/shaders/");
    static Mesh loadMesh(std::string fileName, std::string path = "/engine/mesh");
private:
};


#endif //INC_3DGAMEENGINE_RESOURCELOADER_H
