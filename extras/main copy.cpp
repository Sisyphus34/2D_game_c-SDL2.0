#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

// #include "game.h"
#include "engine.h"
// #include "sprite.h"

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
    Uint32 sprite = (ticks / 100) % 9;
    SDL_Rect srcrect = {sprite * 80, 0, 80, 74};

    // Jump animation atteempt
    Uint32 sprite2 = (ticks / 100) % 12;
    SDL_Rect srcrect2 = {sprite2 * 81, 0, 81, 74};

    /* Alien screen coordinates */
    int dstrect.x = 0, dstrect.y = 0;
    int alien_xvel = 0, alien_yvel = 0;

    /* Initialise SDL and video modes and all that */

    /* Main game loop */
    /* Check for events */
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      /* Look for a keypress */
      case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
          alien_xvel = -1;
          break;
        case SDLK_RIGHT:
          alien_xvel = 1;
          break;
        case SDLK_UP:
          alien_yvel = -1;
          break;
        case SDLK_DOWN:
          alien_yvel = 1;
          break;
        default:
          break;
        }
        break;
      /* We must also use the SDL_KEYUP events to zero the x */
      /* and y velocity variables. But we must also be       */
      /* careful not to zero the velocities when we shouldn't*/
      case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
          /* We check to make sure the alien is moving */
          /* to the left. If it is then we zero the    */
          /* velocity. If the alien is moving to the   */
          /* right then the right key is still press   */
          /* so we don't tocuh the velocity            */
          if (alien_xvel < 0)
            alien_xvel = 0;
          break;
        case SDLK_RIGHT:
          if (alien_xvel > 0)
            alien_xvel = 0;
          break;
        case SDLK_UP:
          if (alien_yvel < 0)
            alien_yvel = 0;
          break;
        case SDLK_DOWN:
          if (alien_yvel > 0)
            alien_yvel = 0;
          break;
        default:
          break;
        }
        break;

      default:
        break;
      }
    }

    /* Update the alien position */
    dstrect.x += alien_xvel;
    dstrect.y += alien_yvel;
  }
  Uint32 ticks = SDL_GetTicks();
  // Walking animation attempt
  Uint32 seconds = ticks / 1000;

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