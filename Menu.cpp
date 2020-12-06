#include "Menu.h"
#include "TextureManager.h"
// #include "GameEngine.h"

// SDL_Event event = GameEngine::event;

Menu::Menu(const char *menu, SDL_Renderer *ren)
{
    renderer = ren;

    menu_texture = TextureManager::LoadTexture("assets/main_menu.png", ren);

    menu_rect.x = 160;
    menu_rect.y = -320;
    menu_rect.w = 480;
    menu_rect.h = 320;
}
Menu::~Menu()
{
}
int Menu::getMenuCoord()
{
    return menu_rect.y;
}
void Menu::menuUpdate(Uint32)
{
    if (menu_rect.y < 160)
    {
        menu_rect.y++;
    }
}
void Menu::menuRender()
{
    SDL_RenderCopy(renderer, menu_texture, NULL, &menu_rect);
}