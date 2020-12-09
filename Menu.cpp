#include "Menu.h"
#include "TextureManager.h"
// #include "GameEngine.h"

// SDL_Event event = GameEngine::event;

Menu::Menu(const char *menu, SDL_Renderer *ren)
{
    renderer = ren;

    menu_texture = TextureManager::LoadTexture(menu, ren);
    arrow_texture = TextureManager::LoadTexture("assets/arrow.png", ren);

    menu_rect.x = 160;
    menu_rect.y = -320;
    menu_rect.w = 480;
    menu_rect.h = 320;

    arrow_rect.x = 325;
    arrow_rect.y = 325;
    arrow_rect.w = 16;
    arrow_rect.h = 16;

    showArrow = false;
    startGame = false;
    state = "start";
}
Menu::~Menu()
{
}
void Menu::setShowArrow(bool show)
{
    showArrow = show;
}
bool Menu::getStartGame()
{
    return startGame;
}
bool Menu::getQuitGame()
{
    return quitGame;
}
bool Menu::getShowArrow()
{
    return showArrow;
}
int Menu::getMenuCoord()
{
    return menu_rect.y;
}
int Menu::getArrowCoord()
{
    return arrow_rect.y;
}

void Menu::menuUpdate(Uint32)
{
    if (menu_rect.y < 160)
    {
        menu_rect.y += 3;
    }
    else
    {
        showArrow = true;
        switch (GameEngine::event.type)
        {
        /* Look for a keypress */
        case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch (GameEngine::event.key.keysym.sym)
            {
            case SDLK_UP:
                arrow_rect.y = 325;
                state = "start"; // row 3 of the sprite sheet "flying animation"
                break;
            case SDLK_DOWN:
                arrow_rect.y = 368; // row 3 of the sprite sheet "flying animation"
                state = "quit";
                break;
            case SDLK_RETURN:
                if (state == "start")
                {
                    startGame = true;
                }
                else
                {
                    quitGame = true;
                }
            default:
                break;
            }
            break;
        }
    }
}
void Menu::menuRender()
{

    SDL_RenderCopy(renderer, menu_texture, NULL, &menu_rect);
    if (showArrow)
    {
        SDL_RenderCopy(renderer, arrow_texture, NULL, &arrow_rect);
    }

    SDL_RenderPresent(renderer);
}