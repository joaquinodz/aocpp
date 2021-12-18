#pragma once

#include <iostream>

#include "SDL.h"
#include "resources.h"
#include "surface.h"

class Game {
public:
    Game();

    bool init();
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();

    SDL_Renderer    *renderer;
    Resources       resources;
    Surface         surface;

private:
    bool            m_isRunning;
    SDL_Window      *m_Window;
};