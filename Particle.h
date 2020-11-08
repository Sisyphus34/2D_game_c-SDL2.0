#pragma once
#include "GameEngine.h"

class Particle
{
public:
    Particle();
    ~Particle();

    // if the lifetime has not ended, draw whatever is
    // appropriate for that particle
    void obj_int(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int width, int height);
    void obj_update_glee();
    void obj_update_blow();

    void obj_render_glee(SDL_Renderer *ren);
    void obj_render_blow(SDL_Renderer *ren);

    void obj_quit();

    int obj_get_x_vel();
    void obj_set_x_vel(float x_val);

    int obj_get_y_vel();
    void obj_set_y_vel(float y_val);

    int obj_get_x_pos();
    void obj_set_x_pos(int new_x);

    int obj_get_y_pos();
    void obj_set_y_pos(int new_y);

    int obj_get_lifetime();
    void obj_set_lifetime(int new_lifetime);

private:
    SDL_Texture *obj_graphic;
    SDL_Rect obj_rect;

    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;

    int width;
    int height;

    int state;
    int lifetime;
};

class ParticleManager
{
public:
    ParticleManager();
    ~ParticleManager();

    void pm_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int width, int height, int type);

    void pm_update();
    void pm_render(SDL_Renderer *ren);
    void pm_quit();

private:
    Particle particles[MAX_PARTS];
    int pos_x;
    int pos_y;
    int part_type;
};