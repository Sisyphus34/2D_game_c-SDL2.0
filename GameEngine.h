#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL_image.h>

// #include "GameObject.h"

class GameEngine
{
public:
  GameEngine();
  ~GameEngine();

  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update(Uint32 ticks);
  void render();
  void clean();
  bool running()
  {
    return isRunning;
  };

  void setIsRunning(bool flip)
  {
    isRunning = flip;
  }

  // static SDL_Renderer *renderer;
  static SDL_Event event;
  static int screenWidth;
  static int screenHeight;

private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};
