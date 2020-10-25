#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class Sprite
{
public:
    Sprite();
    ~Sprite();

    void sprite_init(
        const char *graphic,
        SDL_Renderer *ren,
        int frames,
        int frames_duration,
        int start_width,
        int start_height);
    SDL_Rect sprite_update();
    void sprite_render(SDL_Renderer *ren);
    void sprite_quit();

    int getSpriteFrame();
    int getSpriteFrameCount();
    int getSpriteFrameDuration();

private:
    SDL_Texture *sprite_graphic;
    SDL_Rect frame_rect;
    int frame = 0;
    int frame_count;
    int frame_duration;

    SDL_Renderer *game_renderer;
};

int Sprite::getSpriteFrame()
{
    return (frame);
}
int Sprite::getSpriteFrameCount()
{
    return (frame_count);
}
int Sprite::getSpriteFrameDuration()
{
    return (frame_duration);
}
/**
 * Choose sprite animation based on location of sprite image on sprite sheet
 * rect.y is used to select the ROW of the image!
 * The sprite is drawn onto the player_obj
 * The state dictates which animation to draw
 * Context: which sprite sheet to return src_img from?
 */
// switch(state){
//     case STATE_IDLE:
//         frame_rect.y = IDLE_SPRITE;
//         break;

//     case STATE_MOVE_RIGHT:
//         frame_rect.y = MOVE_SPRITE;
//         break;

//     case STATE_MOVE_LEFT:
//         frame_rect.y = MOVE_SPRITE;
//         break;
//     }

/**
 * Directional change to be drawn right before rendering
 * Low level process - basically, flip then blit
 */
// if (state == STATE_IDLE){
//     flip_sprite == SDL_FLIP_NONE;
// }
// if (state == STATE_MOVE_RIGHT){
//     flip_sprite == SDL_FLIP_NONE;
// }
// if (state == STATE_MOVE_LEFT){
//     flip_sprite == SDL_FLIP_HORIZONTAL;
// }
