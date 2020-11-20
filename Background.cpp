#include "Background.h"
#include "TextureManager.h"
// #include "GameEngine.h"

// SDL_Event event = GameEngine::event;

Background::Background(const char *layer1, const char *layer2, const char *layer3, const char *layer4, SDL_Renderer *ren)
{
    renderer = ren;
    Layer1_texture = TextureManager::LoadTexture("assets/road.png", ren);
    Layer2_texture = TextureManager::LoadTexture("assets/pillars.png", ren);
    Layer3_texture = TextureManager::LoadTexture("assets/hills.png", ren);
    Layer4_texture = TextureManager::LoadTexture("assets/sky_moon.png", ren);
    // Layer5_texture = ...

    layer1_rect.x = 0;
    layer1_rect.y = 0;
    layer1_rect.w = 800;
    layer1_rect.h = 600;

    layer2_rect.x = 0;
    layer2_rect.y = 0;
    layer2_rect.w = 800;
    layer2_rect.h = 600;

    layer3_rect.x = 0;
    layer3_rect.y = 0;
    layer3_rect.w = 800;
    layer3_rect.h = 600;

    layer4_rect.x = 0;
    layer4_rect.y = 0;
    layer4_rect.w = 800;
    layer4_rect.h = 600;

    // layer5_rect.x = 0;
    // layer5_rect.y = 0;
    // layer5_rect.w = 800;
    // layer5_rect.h = 600;
}
Background::~Background()
{
}

void Background::backgroundUpdate(Uint32)
{
}
void Background::backgroundRender()
{
    SDL_RenderCopy(renderer, Layer4_texture, NULL, &layer4_rect);
    SDL_RenderCopy(renderer, Layer3_texture, NULL, &layer3_rect);
    SDL_RenderCopy(renderer, Layer2_texture, NULL, &layer2_rect);
    SDL_RenderCopy(renderer, Layer1_texture, NULL, &layer1_rect);
}