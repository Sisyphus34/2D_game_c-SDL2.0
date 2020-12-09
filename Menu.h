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
    int getArrowCoord();
    bool getShowArrow();
    void setShowArrow(bool show);
    bool getStartGame();
    bool getQuitGame();

private:
    bool showArrow;
    bool startGame;
    bool quitGame;
    std::string state;
    SDL_Texture *menu_texture;
    SDL_Texture *arrow_texture;
    SDL_Rect menu_rect;
    SDL_Rect arrow_rect;
    SDL_Renderer *renderer;
};
