#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>


#include "sprite.h"

SDL_Rect Sprite::sprite_update(){

    int frame_time = (int)(SDL_GetTicks() / frame_duration) % frame_count;

    // std::cout << "Frame" << frame_time << std::end;

    static int last_frame_time = 0;

    if(last_frame_time != frame_time){
        if(frame_time < 1){
            // reset sprite x
            frame_rect.x = 0;
        }
        else{
            // move the src from one framewidth
            frame_rect.x += frame_rect.w;
        }
    }
    last_frame_time = frame_time;

    return (frame_rect);

}

void Sprite::sprite_render(SDL_Renderer* ren){
    SDL_RenderCopy(ren, sprite_graphic, NULL, &frame_rect);
}