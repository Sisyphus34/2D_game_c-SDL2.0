/**
 * Shawn Picardy
 * Assignment 3
 * Cpsc-4160/6140
 */

#include "GameEngine.h"

GameEngine *game = NULL;

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
               game->screenWidth,
               game->screenHeight,
               false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();

        // Update game passing current tick
        game->update(frameStart);
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        // Limit frames to 60fps for consistency
        if (frameDuration > frameTime)
        {
            SDL_Delay(frameDuration - frameTime);
        }
    }
    std::cout << "Game quitting ..." << std::endl;

    // Clean up after yourself dang it!
    game->clean();

    return 0;
}