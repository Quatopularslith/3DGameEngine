//
// Created by Mnenmenth on 1/6/2016.
//

#ifndef INC_3DGAMEENGINE_ENGINE_H
#define INC_3DGAMEENGINE_ENGINE_H


#include <c++/bits/unique_ptr.h>
#include "../game/Game.h"

class Engine {

public:
    static void start();

    static void stop();

private:
    static bool running;
    static int FPS_CAP;

    static void run();

    static void loop();

    static void render();

    static void cleanup();

    static void init();

    static Game *game;

    ~Engine();
};


#endif //INC_3DGAMEENGINE_ENGINE_H
