#pragma once

#include "GameEngine.h"

const int MAX_PARTS = 20;

class Particle
{
public:
    Particle();
    ~Particle();

    void particle_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int start_width, int start_height);
    void particle_update();
    void particle_render(SDL_Renderer *ren);
    void particle_quit();

    int particle_get_x_vel();
    void particle_set_x_vel(float x_val);

    int particle_get_y_vel();
    void particle_set_y_vel(float y_val);

    int particle_get_x_pos();
    void particle_set_x_pos(int new_x);

    int particle_get_y_pos();
    void particle_set_y_pos(int new_y);

    int particle_get_lifetime();
    void particle_set_lifetime(int new_lifetime);

    bool particle_get_isDead();
    void particle_set_isDead(bool died);

private:
    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;

    int width;
    int height;

    bool isDead;
    int lifetime;

    SDL_Texture *particle_texture;
    SDL_Rect particle_rect;
    // SDL_Renderer *particle_renderer;
};

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();

    void pm_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int width, int height);

    void pm_update();
    void pm_render(SDL_Renderer *ren);
    void pm_quit();

private:
    Particle particles[MAX_PARTS];
};