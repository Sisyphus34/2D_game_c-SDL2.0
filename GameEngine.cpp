#include "GameEngine.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Particle.h"

GameObject *flying;
GameObject *hound;
ParticleManager *part_mgr;
// GameObject *slug;
bool run = false;

SDL_Event GameEngine::event;
int GameEngine::screenWidth;
int GameEngine::screenHeight;

GameEngine::GameEngine()
{
    screenWidth = 800;
    screenHeight = 600;
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

    flying = new GameObject("assets/enemy_flying_spritesheet.png", renderer, 10, 10);
    hound = new GameObject("assets/enemy_hound_spritesheet.png", renderer, 250, 250);

    // create a new particle manager and initialize it for use
    part_mgr = new ParticleManager();
    part_mgr->pm_init("assets/enemy-slug.png", renderer, 250, 250, 4, 4);
}
void GameEngine::handleEvents()
{
    SDL_PollEvent(&event);

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
    hound->hitUpdate(ticks);

    // check if flying player collides with hound player
    if (flying->collide(flying, hound))
    {
        run = true;
        hound->set_obj_state("hit");
        hound->hitUpdate(ticks);
    }

    // run particle animation
    if (run)
    {
        part_mgr->pm_update();
    }
    else
    {
        run = false;
    }
}
void GameEngine::render()
{
    SDL_RenderClear(renderer);

    /**
     * This is where we put stuff we want to render
     */
    flying->objRender();
    hound->enemyRender();
    part_mgr->pm_render(renderer);

    SDL_RenderPresent(renderer);
}
void GameEngine::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
