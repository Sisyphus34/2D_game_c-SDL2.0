#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

// #include "game.h"
#include "GameEngine.h"
#include "Sprite.h"

int main(int argc, char **argv)
{

  GameEngine *game = new GameEngine();

  game->eng_init();
  std::cout << "Made it here" << std::endl;

  bool is_running = true;

  SDL_Event event;

  SDL_Surface *image = IMG_Load("hollow_walk.png");
  SDL_Texture *texture = SDL_CreateTextureFromSurface(game->my_renderer, image);

  SDL_Surface *jump_img = IMG_Load("hollow_jump.png");
  SDL_Texture *jump_tex = SDL_CreateTextureFromSurface(game->my_renderer, jump_img);
  SDL_Rect dstrect = {10, 10, 80, 74};
  SDL_Rect dstrect2 = {100, 10, 81, 74};

  while (is_running)
  {
    Uint32 ticks = SDL_GetTicks();
    // Walking animation attempt
    Uint32 seconds = ticks / 1000;
    Uint32 sprite = (ticks / 100) % 9;
    SDL_Rect srcrect = {sprite * 80, 0, 80, 74};

    // Jump animation atteempt
    Uint32 sprite2 = (ticks / 100) % 12;
    SDL_Rect srcrect2 = {sprite2 * 81, 0, 81, 74};

    SDL_WaitEvent(&event);
    // while (SDL_PollEvent(&event) != 0)
    // {
    if (event.type == SDL_QUIT)
    {
      is_running = false;
    }
    switch (event.type)
    {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym)
      {
      case SDLK_LEFT:
        dstrect.x -= 10;
        break;
      case SDLK_RIGHT:
        dstrect.x += 10;
        break;
      case SDLK_DOWN:
        dstrect.y += 10;
        break;
      case SDLK_UP:
        dstrect.y -= 10;
        break;
      default:
        break;
      }
    }
    // }
    std::cout << "Made it here Looping..." << std::endl;
    SDL_Delay(10);
    SDL_RenderClear(game->my_renderer);
    SDL_RenderCopy(game->my_renderer, texture, &srcrect, &dstrect);
    SDL_RenderCopy(game->my_renderer, jump_tex, &srcrect2, &dstrect2);
    SDL_RenderPresent(game->my_renderer);
  }

  game->eng_quit();

  return 0;
}