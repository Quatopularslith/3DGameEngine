//
// Created by Mnenmenth on 1/7/2016.
//

#ifndef INC_3DGAMEENGINE_GAME_H
#define INC_3DGAMEENGINE_GAME_H


#include "../mesh/Mesh.h"
#include "../shader/Shader.h"
#include "../transformation/Transformation.h"

class Game {

public:
    Game();
    ~Game();

    void input();

    void render();

    void update();

private:
    Mesh* mesh;
    Transformation* transform;
    Shader* shader;
    float delta;
    float uniformFloat;
};


#endif //INC_3DGAMEENGINE_GAME_H
