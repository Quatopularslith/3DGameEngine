//
// Created by Mnenmenth on 1/7/2016.
//

#ifndef INC_3DGAMEENGINE_GAME_H
#define INC_3DGAMEENGINE_GAME_H


#include "../mesh/Mesh.h"

class Game {

public:
    Game();
    void input();
    void render();
    void update();
private:
    Mesh mesh;
};


#endif //INC_3DGAMEENGINE_GAME_H
