// CS 4160 - starter code written by Victor Zordan

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

//Screen dimension
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int fps = 60;
const int frame_duration = 1000 / fps;

Uint32 this_start_time;
Uint32 last_count_start_time;
int this_duration;
int fps_counter = 0;
int current_fps;

bool is_running = true;
SDL_Event event;

bool parachute = false;
int counter = 0;

SDL_Window* my_window = NULL;
SDL_Renderer* my_renderer = NULL;
SDL_Event input;

void my_SDL_init(){

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl; 
  }

  //Enable gpu_enhanced textures
  IMG_Init(IMG_INIT_PNG);
  
  my_window = SDL_CreateWindow("Assignment 3", 
			       SDL_WINDOWPOS_CENTERED, 
			       SDL_WINDOWPOS_CENTERED, 
			       SCREEN_WIDTH,
			       SCREEN_HEIGHT, 0);
  my_renderer = SDL_CreateRenderer(my_window,-1,0);

}

int main() 
{ 
  my_SDL_init();

  SDL_Texture* cliff_tex = NULL;
  SDL_Texture* avatar_tex = NULL;
  SDL_Texture* sunset_tex = NULL;
  SDL_Texture* sunset_wave_tex = NULL;
  SDL_Texture* parachute_tex = NULL;
  
  SDL_Surface *cliff_surf = IMG_Load("./first_cliff.png");
  SDL_Surface *sunset_surf = IMG_Load("./sunset.png");
  SDL_Surface *sunset_wave_surf = IMG_Load("./sunset_wave.png");
  SDL_Surface *avatar_surf = IMG_Load("./avatar_edge.png");
  SDL_Surface *parachute_surf = IMG_Load("./parachute.png");




  cliff_tex = SDL_CreateTextureFromSurface(my_renderer, cliff_surf);
  avatar_tex = SDL_CreateTextureFromSurface(my_renderer, avatar_surf);
  sunset_tex = SDL_CreateTextureFromSurface(my_renderer, sunset_surf);
  sunset_wave_tex = SDL_CreateTextureFromSurface(my_renderer, sunset_wave_surf);
  parachute_tex = SDL_CreateTextureFromSurface(my_renderer, parachute_surf);

  SDL_FreeSurface(cliff_surf);
  SDL_FreeSurface(avatar_surf);
  SDL_FreeSurface(sunset_surf);
  SDL_FreeSurface(sunset_wave_surf);
  SDL_FreeSurface(parachute_surf);

  SDL_Rect rect_cliff;
  rect_cliff.x = 0;
  rect_cliff.y = 80;
  rect_cliff.w = 800;
  rect_cliff.h = 400;

  SDL_Rect rect_avatar;
  rect_avatar.x = 10;
  rect_avatar.y = 10;
  rect_avatar.w = 150;
  rect_avatar.h = 150;

  SDL_Rect rect_sunset;
  rect_sunset.x = 0;
  rect_sunset.y = 0;
  rect_sunset.w = 640;
  rect_sunset.h = 480;

  SDL_Rect rect_sunset_wave;
  rect_sunset_wave.x = 0;
  rect_sunset_wave.y = 0;
  rect_sunset_wave.w = 640;
  rect_sunset_wave.h = 480;

  SDL_Rect rect_parachute;
  rect_parachute.x = 0;
  rect_parachute.y = 0;
  rect_parachute.w = 150;
  rect_parachute.h = 150;


  while (is_running)
  {
    this_start_time = SDL_GetTicks();
    // std::cout << "this_start_time = " << this_start_time << std::endl;
    while (SDL_PollEvent(&event))
    {
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
          rect_avatar.x -= 10;
          break;
        case SDLK_RIGHT:
          rect_avatar.x += 10;
          break;
        case SDLK_DOWN:
          rect_avatar.y += 10;
          break;
        case SDLK_UP:
          rect_avatar.y -= 10;
          break;
        default:
          break;
        }
      }
    }
    // rect_avatar.x += 1;
    // if (rect_avatar.x > 80 && !parachute)
    // {
    //   rect_avatar.y += 15;
    // }
    // if (rect_avatar.y > SCREEN_HEIGHT)
    // {
    //   parachute = true;
    // }

    // if(parachute == true){
    //   rect_avatar.x += 1;
    //   rect_avatar.y -= 1;
    //   rect_avatar.h -= .8;
    //   rect_avatar.w -= .8;
    // }
    
    if(rect_avatar.h <= 0){
      rect_avatar.x = 10;
      rect_avatar.y = 10;
      rect_avatar.w = 150;
      rect_avatar.h = 150;
      parachute = false;
    }
    counter++;
    // SDL_Delay(10);
    SDL_RenderClear(my_renderer);

    if(counter % 8 == 0){
      SDL_RenderCopy(my_renderer, sunset_tex, NULL, &rect_sunset);
    }
    else{
      SDL_RenderCopy(my_renderer, sunset_wave_tex, NULL, &rect_sunset);
    }

    SDL_RenderCopy(my_renderer, cliff_tex, NULL, &rect_cliff);
    
    
    

    if(parachute == true){
    SDL_RenderCopy(my_renderer, parachute_tex, NULL, &rect_avatar);
    }
    else{
      SDL_RenderCopy(my_renderer, avatar_tex, NULL, &rect_avatar);
    }
    SDL_RenderPresent(my_renderer);

    fps_counter++;
    if (this_start_time >= (last_count_start_time + 1000))
    {
        last_count_start_time = this_start_time;
        current_fps = fps_counter;
        fps_counter = 0;
      }

      std::cout << "fps = " << current_fps << std::endl;

      this_duration = SDL_GetTicks() - this_start_time;

      if(this_duration < frame_duration){
        SDL_Delay(frame_duration - this_duration);
      }
    }

  SDL_DestroyRenderer(my_renderer);

  SDL_DestroyWindow(my_window);

  IMG_Quit();
  SDL_Quit();
  
  return 0; 
}
