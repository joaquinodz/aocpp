#include <SDL_image.h>
#include "Game.h"

Game::Game()
{
    m_Window = nullptr;
    renderer = nullptr;

    // If the game initializes correctly, isRunning will be true and the game loop will start.
    m_isRunning = this->init();

    // If the resources were successfully loaded, isRunning will be true and the game loop will start.
    //m_isRunning = resources.loadResources();
}

bool Game::init()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cout << "Oops, i can't initialize the SDL context. Error " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "Oops, i can't get seem to get support for PNG files. Error " << SDL_GetError() << std::endl;
        return false;
    }

    m_Window = SDL_CreateWindow("Argentum Online", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (m_Window == nullptr)
    {
        std::cout << "Oops, i can't create the window. Error " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        std::cout << "Oops, there's been a problem while creating the renderer. Error " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            m_isRunning = false;
            break;

        default:
            break;
    }
}
void Game::update()
{

}

void Game::render()
{
    SDL_RenderClear(renderer);

    // Draw things

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    m_isRunning = false;

    if(m_Window != nullptr) SDL_DestroyWindow(m_Window);
    if(renderer != nullptr) SDL_DestroyRenderer(renderer);
    
    SDL_Quit();

    std::cout << "Thank you for playing! See you later, i hope ;)" << std::endl;
}

bool Game::running()
{
    return m_isRunning;
}