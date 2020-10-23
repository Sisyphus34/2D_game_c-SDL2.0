#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

// #include "game.h"
#include "engine.h"


int main(int argc, char ** argv){

    // my_SDL_init();

    GameEngine* game = new GameEngine();

    game->eng_init();
    std::cout << "Made it here" << std::endl;

    bool is_running = true;

    SDL_Event event;

    while (is_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running = false;
            }
        }
      std::cout << "Made it here Looping..." << std::endl;
      SDL_Delay(10);
    }

  game->eng_quit();
  
  return 0;
}