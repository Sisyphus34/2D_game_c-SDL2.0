#pragma once
#include "GameEngine.h"
#include "Particle.h"

class GameObject
{

public:
    GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y, ParticleManager *particleMgr);
    ~GameObject();

    void objUpdate(Uint32);
    void hitUpdate(Uint32);
    void objRender();
    void enemyRender();
    int getXpos();
    int getYpos();
    bool collide(GameObject *a, GameObject *b);

    int get_obj_rectX();
    int get_obj_rectY();

    void set_obj_state(std::string new_state);
    std::string get_obj_state();

private:
    int xpos;
    int ypos;
    std::string state;

    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
    ParticleManager *objPartcleMgr;
};
