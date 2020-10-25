#pragma once
#include "GameEngine.h"

class GameObject
{

public:
    GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y);
    ~GameObject();

    void objUpdate(Uint32);
    void objRender();

private:
    int xpos;
    int ypos;
    std::string state;

    SDL_Texture *
        objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
};
