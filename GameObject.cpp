#include "GameObject.h"
#include "TextureManager.h"
// #include "GameEngine.h"

// SDL_Event event = GameEngine::event;

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y)
{
    renderer = ren;
    objTexture = TextureManager::LoadTexture(texturesheet, ren);

    xpos = x;
    ypos = y;

    // Set source rectangle to same size as sprite (16px x 16px)
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4; // increase scale for easier viewing
    destRect.h = srcRect.h * 4; // increase scale for easier viewing
}

int GameObject::getXpos()
{
    return xpos;
}
int GameObject::getYpos()
{
    return ypos;
}

void GameObject::objUpdate(Uint32 ticks)
{
    int max_width = GameEngine::screenWidth;
    int max_height = GameEngine::screenHeight;
    // SDL_Event event;
    // xpos++;
    // ypos++;

    // The spritesheet has 4 images used to create the animations
    Uint32 sprite = (ticks / 100) % 4;

    // // Set source rectangle to same size as sprite (16px x 16px)
    // srcRect.h = 16;
    // srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4; // increase scale for easier viewing
    destRect.h = srcRect.h * 4; // increase scale for easier viewing
    if (xpos >= 0 &&
        xpos <= max_width &&
        ypos >= 0 &&
        ypos <= max_height)
    {
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
                srcRect.y = 16; // row 2 of the sprite sheet "walking animation"
                state = "Move_Left";
                break;
            case SDLK_RIGHT:
                xpos += 4;
                srcRect.x = sprite * 16;
                srcRect.y = 16; // row 2 of the sprite sheet "walking animation"
                state = "Move_Right";
                break;
            case SDLK_UP:
                ypos -= 6;
                srcRect.x = sprite * 16;
                srcRect.y = 32; // row 3 of the sprite sheet "flying animation"
                break;
            case SDLK_DOWN:
                ypos += 6;
                srcRect.x = sprite * 16;
                srcRect.y = 32; // row 3 of the sprite sheet "flying animation"
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
                // row 0 of the sprite sheet "idle animation" upon key release
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
void GameObject::enemyUpdate(Uint32 ticks)
{

    // SDL_Event event;
    // xpos++;
    // ypos++;

    // The spritesheet has 4 images used to create the animations
    Uint32 sprite = (ticks / 100) % 4;

    // Set source rectangle to same size as sprite (16px x 16px)
    srcRect.h = 16;
    srcRect.w = 16;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 4; // increase scale for easier viewing
    destRect.h = srcRect.h * 4; // increase scale for easier viewing

    /* Check for events */
    switch (GameEngine::event.type)
    {
    /* Look for a keypress */
    case SDL_KEYDOWN:
        /* Check the SDLKey values and move change the coords */
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_a:
            xpos -= 4;
            srcRect.x = sprite * 16;
            srcRect.y = 16; // row 2 of the sprite sheet "walking animation"
            state = "Move_Left";
            break;
        case SDLK_d:
            xpos += 4;
            srcRect.x = sprite * 16;
            srcRect.y = 16; // row 2 of the sprite sheet "walking animation"
            state = "Move_Right";
            break;
        case SDLK_w:
            ypos -= 6;
            // srcRect.x = sprite * 16;
            // srcRect.y = 32; // row 3 of the sprite sheet "flying animation"
            break;
        case SDLK_s:
            ypos += 6;
            // srcRect.x = sprite * 16;
            // srcRect.y = 32; // row 3 of the sprite sheet "flying animation"
            state = "Move_Down";
            break;
        default:
            break;
        }
        break;

    case SDL_KEYUP:
        switch (GameEngine::event.key.keysym.sym)
        {
        case SDLK_a:
            // row 0 of the sprite sheet "idle animation" upon key release
            if (xpos < 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_d:
            if (xpos > 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_w:
            if (ypos < 0)
            {
                srcRect.x = sprite * 16;
                srcRect.y = 0;
                state = "";
                break;
            }
        case SDLK_s:
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

void GameObject::enemyRender()
{
    if (state == "Move_Left")
    {
        SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    }
    // else if (state == "Move_Down")
    // {
    //     SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_VERTICAL);
    // }
    else
        SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}
bool GameObject::collide(GameObject *a, GameObject *b)
{
    int aLeft = a->getXpos();
    int aRight = aLeft + 64;
    int aTop = a->getYpos();
    int aBottom = aTop + 64;

    int bLeft = b->getXpos();
    int bRight = bLeft + 64;
    int bTop = b->getYpos();
    int bBottom = bTop + 64;

    if (aRight < bLeft)
    {
        return false;
    }
    if (aLeft > bRight)
    {
        return false;
    }
    if (aBottom < bTop)
    {
        return false;
    }
    if (aTop > bBottom)
    {
        return false;
    }
    return true;
}