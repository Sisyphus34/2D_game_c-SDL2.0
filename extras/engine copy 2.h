#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class GameEngine
{
public:
  GameEngine();
  ~GameEngine();

  void handleEvents();
  void eng_init();
  void eng_create_window();
  void eng_create_renderer();
  void eng_quit();
  SDL_Window *my_window;
  SDL_Renderer *my_renderer;
  SDL_Event input;
};
// GameEngine
//     init
// SDL_init
// SDL_CreateWindow
// SDL _CreateRender
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// SDL_Window* my_window = NULL;
// SDL_Renderer* my_renderer = NULL;
// SDL_Event input;

GameEngine::GameEngine() {}
GameEngine::~GameEngine() {}

void GameEngine::eng_init()
{
  // my_window = NULL;
  // my_renderer = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);

  my_window = SDL_CreateWindow("Assignment 3",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window, -1, 0);
  SDL_SetRenderDrawColor(my_renderer, 147, 106, 177, 255);
  SDL_RenderClear(my_renderer);
}

void GameEngine::handleEvents()
{

  SDL_Event game_event;
  SDL_PollEvent(&game_event);

  // if (game_event.type == SDL_QUIT)
  //   game_is_running = false;
}

void GameEngine::eng_quit()
{
  SDL_DestroyRenderer(my_renderer);

  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  std::cout << "Quitting..." << std::endl;
}

//     updateMechanics
// SDL_Rect
// Objects - update
/**
             * Set the state based off velocity or button press / event
             * How quickly can the event change be passed to the state variable
             *  @ highest level???
             */
// if (x_vel == 0 && y_vel == 0){
//   state = STATE_IDLE;
// }
// if (x_vel > 0){
//   state = STATE_MOVE_RIGHT;
// }
// if (x_vel < 0){
//   state = STATE_MOVE_LEFT;
// }
//     render
// SDL_RenderClear
// SDL_(copy)
// SDL_RenderPresent
//     quit
// destroy

// GameObject
//     init
//         IMG_Load
//         Textures
//     update
//         SDL_Rect.x += 5;
//     Renderer
//         SDL_RenderCopy
//     Quit
//         Destroy