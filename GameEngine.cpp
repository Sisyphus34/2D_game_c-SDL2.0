#include "GameEngine.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject *flying;
// GameObject *hound;
// GameObject *slug;

SDL_Event GameEngine::event;

GameEngine::GameEngine()
{
}
GameEngine::~GameEngine() {}
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    //Enable gpu_enhanced textures
    // IMG_Init(IMG_INIT_PNG);

    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("Assignment 3",
                                  xpos,
                                  ypos,
                                  width,
                                  height,
                                  flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 147, 106, 177, 255);

        isRunning = true;
    }
    else
    {
        isRunning = false;
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    flying = new GameObject("assets/enemy_flying_spritesheet.png", renderer, 0, 0);
    // hound = new GameObject("assets/enemy-hound.png", renderer, 150, 0);
    // slug = new GameObject("assets/enemy-slug.png", renderer, 300, 0);
}
void GameEngine::handleEvents()
{
    // SDL_Event event = GameEngine::event;
    SDL_PollEvent(&event);
    // SDL_WaitEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void GameEngine::update(Uint32 ticks)
{
    flying->objUpdate(ticks);
    // hound->objUpdate();
    // slug->objUpdate();
}
void GameEngine::render()
{
    SDL_RenderClear(renderer);

    /**
     * This is where we put stuff we want to render
     */

    flying->objRender();
    // hound->objRender();
    // slug->objRender();

    SDL_RenderPresent(renderer);
}
void GameEngine::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
