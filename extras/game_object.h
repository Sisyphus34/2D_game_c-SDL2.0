#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class GameObject
{

public:
    GameObject(SDL_Renderer *ren);
    ~GameObject();

    void obj_init();
    void obj_update();
    void obj_render();
    void obj_quit();

private:
    SDL_Renderer *obj_renderer;
    SDL_Texture *obj_graphic;
    SDL_Rect obj_rect;

    GameObject::GameObject(SDL_Renderer *ren)
    {
        obj_renderer = ren;
    }

    GameObject::~GameObject() {}

    void GameObject::obj_init()
    {
        // area of graphical memory that can be drawn to
        SDL_Surface *img_surface = IMG_Load("");

        obj_graphic = SDL_CreateTextureFromSurface(obj_renderer, img_surface);
        SDL_FreeSurface(img_surface);
    }
};

#endif