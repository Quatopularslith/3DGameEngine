//
// Created by Razim on 3/2/2016.
//

#ifndef INC_3DGAMEENGINE_RESOURCELOADER_H
#define INC_3DGAMEENGINE_RESOURCELOADER_H


#include <string>
#include "../mesh/Mesh.h"

class ResourceLoader {
public:

    struct MeshVerts {
        Vertex* vertices;
        int* indices;
    };

    static const char *loadShader(std::string fileName, std::string path = "engine/shaders/");

    static MeshVerts loadMesh(std::string fileName, std::string path = "engine/mesh/");

private:
};


#endif //INC_3DGAMEENGINE_RESOURCELOADER_H
