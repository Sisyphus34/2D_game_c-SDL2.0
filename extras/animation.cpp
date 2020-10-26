#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

//  Hollow Knight sprite sheet = 822 X 75 with 10 sprites

int main(int argc, char **argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow("SDL2 Sprite Sheets",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *image = IMG_Load("hollow_walk.png");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_Surface *jump_img = IMG_Load("hollow_jump.png");
    SDL_Texture *jump_tex = SDL_CreateTextureFromSurface(renderer, jump_img);

    SDL_SetRenderDrawColor(renderer, 161, 90, 116, 255);
    SDL_RenderClear(renderer);

    while (!quit)
    {
        Uint32 ticks = SDL_GetTicks();
        // Walking animation attempt
        Uint32 seconds = ticks / 1000;
        Uint32 sprite = (ticks / 100) % 9;
        SDL_Rect srcrect = {sprite * 80, 0, 80, 74};
        SDL_Rect dstrect = {10, 10, 80, 74};

        // Jump animation atteempt
        Uint32 sprite2 = (ticks / 100) % 12;
        SDL_Rect srcrect2 = {sprite2 * 81, 0, 81, 74};
        SDL_Rect dstrect2 = {100, 10, 81, 74};

        // SDL_WaitEvent(&event);

        while (SDL_PollEvent(&event) != NULL)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        // switch (event.type)
        // {
        //     case SDL_QUIT:
        //         quit = true;
        //         break;
        // }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
        SDL_RenderCopy(renderer, jump_tex, &srcrect2, &dstrect2);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyTexture(jump_tex);
    SDL_FreeSurface(jump_img);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}