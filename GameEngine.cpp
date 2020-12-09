#include "GameEngine.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Particle.h"
#include "Background.h"
#include "Menu.h"

Menu *main_menu;
Menu *pause_screen;
Background *background;
GameObject *flying;
GameObject *hound;
ParticleManager *part_mgr;
ParticleManager *part_mgr2;

// GameObject *slug;
bool run = false;
bool in_menu = true;
bool pause = false;

SDL_Event GameEngine::event;
int GameEngine::screenWidth;
int GameEngine::screenHeight;

GameEngine::GameEngine()
{
    screenWidth = 800;
    screenHeight = 640;
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
        // SDL_SetRenderDrawColor(renderer, 147, 106, 177, 255);

        isRunning = true;
    }
    else
    {
        isRunning = false;
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    background = new Background(
        "assets/road.png",
        "assets/pillars.png",
        "assets/hills.png",
        "assets/sky_moon.png",
        renderer);

    main_menu = new Menu("assets/main_menu.png", renderer);
    pause_screen = new Menu("assets/pause_screen.png", renderer);

    part_mgr = new ParticleManager();

    // part_mgr->pm_init("assets/enemy-slug.png", renderer, 10, 450, 4, 4);
    // std::cout << "got here" << std::endl;
    flying = new GameObject("assets/enemy_flying_spritesheet.png", renderer, 10, 500, part_mgr);
    part_mgr2 = new ParticleManager();

    // part_mgr2->pm_init("assets/enemy-slug.png", renderer, 450, 450, 4, 4);

    // std::cout << "got here 2" << std::endl;
    hound = new GameObject("assets/enemy_hound_spritesheet.png", renderer, 450, 500, part_mgr2);

    // create a new particle manager and initialize it for use
    // part_mgr = new ParticleManager();
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

    switch (GameEngine::event.type)
    {
    /* Look for a keypress */
    case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_SPACE:
            pause = !pause;
        default:
            break;
        }
        break;
    }
    if (!main_menu->getStartGame())
    {
        main_menu->menuUpdate(ticks);
        pause_screen->menuUpdate(ticks);
        if (main_menu->getQuitGame())
        {
            isRunning = false;
        }
    }
    else
    {
        if (!pause)
        {
            flying->objUpdate(ticks);
            hound->enemyUpdate(ticks);

            // check if flying player collides with hound player
            if (flying->collide(flying, hound))
            {
                run = true;
                hound->set_obj_state("hit");
                hound->enemyUpdate(ticks);
            }
        }
    }
}
void GameEngine::render()
{
    /**
     * This is where we put stuff we want to render
     */
    SDL_RenderClear(renderer);
    if (!main_menu->getStartGame())
    {

        background->backgroundRender();
        main_menu->menuRender();
    }
    else if (pause)
    {
        /**
         * If game is paused, 
         * set showArrow to false to prevent the main menu arrow selector from renderering,
         * show the game object and also the "PAUSE" screen
         */
        pause_screen->setShowArrow(false);
        background->backgroundRender();
        flying->objRender();
        hound->enemyRender();
        pause_screen->menuRender();
    }
    else
    {
        background->backgroundRender();

        flying->objRender();
        hound->enemyRender();
    }

    SDL_RenderPresent(renderer);
    // part_mgr->pm_render(renderer);
}
void GameEngine::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
