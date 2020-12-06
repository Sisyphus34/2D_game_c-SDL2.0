#pragma once
#include "GameEngine.h"

class Background
{

public:
    Background(const char *layer1, const char *layer2, const char *layer3, const char *layer4, SDL_Renderer *ren);
    ~Background();

    void backgroundUpdate(Uint32);
    void backgroundRender();

private:
    SDL_Texture *Layer1_texture;
    SDL_Texture *Layer2_texture;
    SDL_Texture *Layer3_texture;
    SDL_Texture *Layer4_texture;
    // SDL_Texture *Layer5_texture;
    SDL_Rect layer1_rect, layer2_rect, layer3_rect, layer4_rect;
    SDL_Renderer *renderer;
};