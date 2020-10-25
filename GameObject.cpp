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
    // SDL_Rect srcrect = {sprite * 16, 0, 16, 16};
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4;
    destRect.h = srcRect.h * 4;

    /* Alien screen coordinates */
    // int dstrect.x = 0, dstrect.y = 0;

    /* Check for events */

    switch (GameEngine::event.type)
    {
    /* Look for a keypress */
    case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            xpos -= 2;
            srcRect.x = sprite * 16;
            state = "Move_Left";
            break;
        case SDLK_RIGHT:
            xpos += 2;
            srcRect.x = sprite * 16;
            state = "Move_Right";
            break;
        case SDLK_UP:
            ypos -= 2;
            break;
        case SDLK_DOWN:
            ypos += 2;
            break;
        default:
            break;
        }
        break;
    /* We must also use the SDL_KEYUP events to zero the x */
    /* and y velocity variables. But we must also be       */
    /* careful not to zero the velocities when we shouldn't*/
    case SDL_KEYUP:
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            /* We check to make sure the alien is moving */
            /* to the left. If it is then we zero the    */
            /* velocity. If the alien is moving to the   */
            /* right then the right key is still press   */
            /* so we don't tocuh the velocity            */
            if (xpos < 0)
            {
                srcRect.x = 0;
                // srcRect.y = 0;
                break;
            }
        case SDLK_RIGHT:
            if (xpos > 0)
            {
                srcRect.x = 0;
                // srcRect.y = 0;
                break;
            }
        case SDLK_UP:
            if (ypos < 0)
            {
                srcRect.x = 0;
                // srcRect.y = 0;
                break;
            }
        case SDLK_DOWN:
            if (ypos > 0)
            {
                srcRect.x = 0;
                // srcRect.y = 0;
                break;
            }
        default:
            srcRect.x = 0;
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
    else
        SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}