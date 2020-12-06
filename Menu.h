#pragma once
#include "GameEngine.h"

class Menu
{

public:
    Menu(const char *menu, SDL_Renderer *ren);
    ~Menu();

    void menuUpdate(Uint32);
    void menuRender();
    int getMenuCoord();

private:
    SDL_Texture *menu_texture;
    SDL_Rect menu_rect;
    SDL_Renderer *renderer;
};
