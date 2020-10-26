#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class Player
{
public:
    Player();
    ~Player();

    void player_init();
    void player_update();
    void player_render(SDL_Renderer *ren);
    void player_quit();

    int obj_get_x_vel();
    int obj_get_y_vel();

private:
    // SDL_Renderer *player_renderer;

    SDL_Texture *player_graphic;
    SDL_Rect player_rect;
};

#endif