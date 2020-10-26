#include "GameObject.h"
#include "TextureManager.h"
#include "GameEngine.h"

// SDL_Event event = GameEngine::event;

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;
}

void GameObject::objUpdate(Uint32 ticks)
{

    // SDL_Event event;
    // xpos++;
    // ypos++;
    Uint32 sprite = (ticks / 100) % 4;
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

    /* Check for events */

    switch (GameEngine::event.type)
    {
    /* Look for a keypress */
    case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            xpos -= 4;
            srcRect.x = sprite * 16;
            srcRect.y = 16;
            state = "Move_Left";
            break;
        case SDLK_RIGHT:
            xpos += 4;
            srcRect.x = sprite * 16;
            srcRect.y = 16;
            state = "Move_Right";
            break;
        case SDLK_UP:
            ypos -= 6;
            srcRect.x = sprite * 16;
            srcRect.y = 32;
            break;
        case SDLK_DOWN:
            ypos += 6;
            srcRect.x = sprite * 16;
            srcRect.y = 32;
            state = "Move_Down";
            break;
        default:
            break;
        }
        break;

    case SDL_KEYUP:
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_LEFT:

            if (xpos < 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_RIGHT:
            if (xpos > 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_UP:
            if (ypos < 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_DOWN:
            if (ypos > 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        default:
            srcRect.x = sprite * 16;
            srcRect.y = 0;
            state = "";
            break;
        }
        break;

    default:
        break;
    }
}

void GameObject::objRender()
{
    if (state == "Move_Left")
    {
        SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    else if (state == "Move_Down")
    {
        SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_VERTICAL);
    }
    else
        SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}