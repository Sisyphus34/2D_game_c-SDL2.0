

#include <iostream>
#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>

#include "player.h"
#include "sprite.h"


void Player::player_update(){
    // frame_rect = object_sprite->sprite_update(state);

    // if (state == STATE_IDLE){
    //     flip_sprite == SDL_FLIP_NONE;
    // }
    // if (state == STATE_MOVE_RIGHT){
    //     flip_sprite == SDL_FLIP_NONE;
    // }
    // if (state == STATE_MOVE_LEFT){
    //     flip_sprite == SDL_FLIP_HORIZONTAL;
    // }
}

void Player::player_render(SDL_Renderer *ren){
    // SDL_RenderCopyEx(ren, obj_graphic, &frame_rect, &obj_rect, 0.0, NULL, flip_sprite);
    // SDL_RenderCopy(ren, obj_graphic, &frame_rect, &obj_rect);
}

void Player::player_quit(){
    // SDL_DestroyTexture(obj_graphic);
}