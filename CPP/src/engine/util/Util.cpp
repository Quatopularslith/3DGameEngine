//
// Created by Razim on 3/2/2016.
//

#include "Util.h"
#include <algorithm>
#include <sstream>

/*std::array<GLfloat> Util::createFlippedBuffer(Vertex *vertices) {
    std::vector<GLfloat> buffer;

    for(int i = 0; i < sizeof(vertices); i++){
        buffer.push_back(vertices[i].getPos().getX());
        buffer.push_back(vertices[i].getPos().getY());
        buffer.push_back(vertices[i].getPos().getZ());
    }

    std::reverse(buffer.begin(), buffer.end());

    std::array<GLfloat, sizeof(buffer)> buffarr;
    std::copy(buffer.end(), buffer.begin(), buffarr);

    return buffarr;
}

std::array<GLfloat> Util::createFlippedBuffer(int *vertices) {

    std::array<GLfloat, sizeof(vertices)> buffarr;
    std::copy(std::end(vertices), std::begin(vertices), buffarr);

    return buffarr;
}*/

GLfloat *Util::createFlippedBuffer(Matrix4f value) {
    std::vector<GLfloat> buffer;

    for (int i = 0; i <= sizeof(value); i++) {
        for (int j = 0; j <= sizeof(value); j++) {
            buffer.push_back(value.get(i, j));
        }
    }

    return buffer.data();
}

std::vector<std::string> Util::splitString(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;
    while (std::getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}
