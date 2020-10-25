#include "GameEngine.h"

GameEngine *game = nullptr;

int main(int argc, const char *argv[])
{
    const int FPS = 60;
    const int frameDuration = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new GameEngine();

    game->init("Shawn's Engine",
               SDL_WINDOWPOS_CENTERED,
               SDL_WINDOWPOS_CENTERED,
               800,
               600,
               false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDuration > frameTime)
        {
            SDL_Delay(frameDuration - frameTime);
        }
    }
    std::cout << "Game quitting ..." << std::endl;
    game->clean();

    return 0;
}