#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::objUpdate()
{

    xpos++;
    ypos++;

    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;
}

void GameObject::objRender()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}