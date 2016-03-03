//
// Created by Razim on 3/2/2016.
//

#include "ResourceLoader.h"
#include "Util.h"
#include <fstream>
#include <iostream>

const char *ResourceLoader::loadShader(std::string fileName, std::string path) {
    std::string shader = "";
    std::ifstream file(path + fileName);

    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            shader += (line + "\n");
        }
    } else {
        std::cout << "Shader failed to load" << std::endl;
    }
    return shader.c_str();
}

ResourceLoader::MeshVerts ResourceLoader::loadMesh(std::string fileName, std::string path) {
    std::vector<Vertex> vertices;
    std::vector<int> indices;

    std::string line;
    std::ifstream file(path + fileName, std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::vector<std::string> tokens = Util::splitString(line, ' ');
            if (tokens[0] == "v") {
                vertices.push_back(Vertex(Vector3f(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]))));
            } else if (tokens[0] == "f") {
                indices.push_back(std::stoi(tokens[1]) - 1);
                indices.push_back(std::stoi(tokens[2]) - 1);
                indices.push_back(std::stoi(tokens[3]) - 1);
            }
        }
    } else {
        std::cout << "Mesh failed to load" << std::endl;
    }

    MeshVerts mesh;
    mesh.vertices = vertices.data();
    mesh.indices = indices.data();

    return mesh;
}
