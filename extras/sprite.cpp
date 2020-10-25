#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include "Sprite.h"

Sprite::Sprite();
Sprite::~Sprite();

Sprite::sprite_init()
{
}

SDL_Rect Sprite::sprite_update()
{

    int frame_time = (int)(SDL_GetTicks() / frame_duration) % frame_count;

    // std::cout << "Frame" << frame_time << std::end;

    static int last_frame_time = 0;

    // Uint32 ticks = SDL_GetTicks();
    // // Walking animation attempt
    // Uint32 seconds = ticks / 1000;
    // Uint32 sprite = (ticks / 100) % 9;
    // SDL_Rect srcrect = { sprite * 80, 0, 80, 74 };
    // SDL_Rect dstrect = { 10, 10, 80, 74 };

    // // Jump animation atteempt
    // Uint32 sprite2 = (ticks / 100) % 12;
    // SDL_Rect srcrect2 = { sprite2 * 81, 0, 81, 74 };
    // SDL_Rect dstrect2 = { 100, 10, 81, 74 };

    if (last_frame_time != frame_time)
    {
        if (frame_time < 1)
        {
            // reset sprite x
            frame_rect.x = 0;
        }
        else
        {
            // move the src from one framewidth
            frame_rect.x += frame_rect.w;
        }
    }
    last_frame_time = frame_time;

    return (frame_rect);
}

void Sprite::sprite_render(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, sprite_graphic, NULL, &frame_rect);
}