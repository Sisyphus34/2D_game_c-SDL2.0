#include "Particle.h"
#include "TextureManager.h"

Particle::Particle()
{
}

Particle::~Particle()
{
}

void Particle::obj_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int start_w, int start_h)
{

    obj_graphic = TextureManager::LoadTexture(graphic, ren);
    obj_renderer = ren;

    x_pos = (float)start_x;
    y_pos = (float)start_y;

    width = start_w;
    height = start_h;
}

void Particle::obj_update_blow()
{
    x_pos += x_vel; //move the object pos = old_pos + one timestep * x_vel
    y_pos += y_vel; //move the object pos = old_pos + one timestep * y_vel

    y_vel += 9.8 * 100.0 / 36000.0; //100 px/meter

    if (lifetime > 0)
    {
        /**
         * if(x_pos < (GAME_BOUND_LEFT_X - width/2)) x_vel *= -1;
         * if(x_pos > (GAME_BOUND_RIGHT_X - width/2)) x_vel *= -1;
         * if(y_pos < (GAME_BOUND_UPPER_Y - height/2)) y_vel *= -1;
         * if(y_pos > (GAME_BOUND_LOWER_Y - height/2)) y_vel *= -1;
         * 
         * if(x_pos < (GAME_BOUND_LEFT_X - width/2)) (GAME_BOUND_LEFT_X - width/2);
         * if(x_pos > (GAME_BOUND_RIGHT_X - width/2)) (GAME_BOUND_RIGHT_X - width/2);
         * if(y_pos < (GAME_BOUND_UPPER_Y - height/2)) (GAME_BOUND_UPPER_Y - height/2);
         * if(y_pos > (GAME_BOUND_LOWER_Y - height/2)) (GAME_BOUND_LOWER_Y - height/2);
         * 
         */

        obj_rect.x = (int)x_pos;
        obj_rect.y = (int)y_pos;
        obj_rect.w = (int)width / 2 + width * (int)(10 * lifetime / 100);
        obj_rect.h = (int)height / 2 + height * (int)(10 * lifetime / 100);
    }
    lifetime -= 1;
}

void Particle::obj_update_glee()
{
    x_pos += x_vel; //move the object pos = old_pos + one timestep * x_vel
    y_pos += y_vel; //move the object pos = old_pos + one timestep * y_vel

    // y_vel += 9.8 * 100.0 / 36000.0; //100 px/meter

    if (lifetime > 0)
    {
        /**
         * if(x_pos < (GAME_BOUND_LEFT_X - width/2)) x_vel *= -1;
         * if(x_pos > (GAME_BOUND_RIGHT_X - width/2)) x_vel *= -1;
         * if(y_pos < (GAME_BOUND_UPPER_Y - height/2)) y_vel *= -1;
         * if(y_pos > (GAME_BOUND_LOWER_Y - height/2)) y_vel *= -1;
         * 
         * if(x_pos < (GAME_BOUND_LEFT_X - width/2)) (GAME_BOUND_LEFT_X - width/2);
         * if(x_pos > (GAME_BOUND_RIGHT_X - width/2)) (GAME_BOUND_RIGHT_X - width/2);
         * if(y_pos < (GAME_BOUND_UPPER_Y - height/2)) (GAME_BOUND_UPPER_Y - height/2);
         * if(y_pos > (GAME_BOUND_LOWER_Y - height/2)) (GAME_BOUND_LOWER_Y - height/2);
         * 
         */

        obj_rect.x = (int)x_pos;
        obj_rect.y = (int)y_pos;
        obj_rect.w = (int)width;
        obj_rect.h = (int)height;
    }
    lifetime -= 1;
}

void Particle::obj_render_blow(SDL_Renderer *ren)
{
    if (lifetime > 0)
    {
        SDL_RenderCopy(ren, obj_graphic, NULL, &obj_rect);
    }
}
void Particle::obj_render_glee(SDL_Renderer *ren)
{
    if (lifetime > 0)
    {
        SDL_SetTextureAlphaMod(obj_graphic, (int)255 * lifetime / 20.0);
        SDL_RenderCopy(ren, obj_graphic, NULL, &obj_rect);
    }
    else
    {
        SDL_SetTextureAlphaMod(obj_graphic, 255);
    }
}

void Particle::obj_quit()
{
    SDL_DestroyTexture(obj_graphic);
}
int Particle::obj_get_x_vel()
{
    return (int)x_vel;
}
void Particle::obj_set_x_vel(float x_val)
{
    x_vel = x_val;
}
int Particle::obj_get_y_vel()
{
    return (int)y_vel;
}
void Particle::obj_set_y_vel(float y_val)
{
    y_vel = y_val;
}

int Particle::obj_get_x_pos()
{
    return (int)x_pos;
}
void Particle::obj_set_x_pos(int new_x)
{
    x_pos = new_x;
}

int Particle::obj_get_y_pos()
{
    return (int)y_pos;
}
void Particle::obj_set_y_pos(int new_y)
{
    y_pos = new_y;
}
int Particle::obj_get_lifetime()
{
    return lifetime;
}

void Particle::obj_set_lifetime(int new_lifetime)
{
    lifetime = new_lifetime;
}

ParticleManager::ParticleManager()
{
}
ParticleManager::~ParticleManager() {}

void ParticleManager::pm_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int start_w, int start_h, int type)
{
    srand(5);
    part_type = type;

    int max_parts = MAX_PARTS;

    if (part_type == PART_TYPE_BLOW)
    {
        max_parts = MAX_PARTS_BLOW;
        for (int i = 0; i < max_parts; i++)
        {
            particles[i].obj_init(graphic, ren, start_x, start_y, start_w, start_h);
            particles[i].obj_set_x_vel(3.0 - (rand() % 60) / 10.0);
            particles[i].obj_set_y_vel(0 - (rand() % 60) / 10.0);
            particles[i].obj_set_lifetime(20 + (rand() % 10));
        }
    }
    if (part_type == PART_TYPE_GLEE)
    {
        // std::cout << "Yumm Init" << std:: endl;
        for (int i = 0; i < max_parts; i++)
        {
            particles[i].obj_set_lifetime(10 + (rand() % 10));

            switch (rand() % 4)
            {
            case 0:
                particles[i].obj_init(graphic, ren, start_x, start_y - 17 + rand() % 34, start_w, start_h);
                particles[i].obj_set_x_vel(5 + (rand() % 50) / 10.0);
                particles[i].obj_set_y_vel(0);
                break;
            case 1:
                particles[i].obj_init(graphic, ren, start_x, start_y + 17 + rand() % 34, start_w, start_h);
                particles[i].obj_set_x_vel(-5 + (rand() % 50) / -10.0);
                particles[i].obj_set_y_vel(0);
                break;
            case 2:
                particles[i].obj_init(graphic, ren, start_x, start_y + 17 + rand() % 34, start_w, start_h);
                particles[i].obj_set_x_vel(4 + (rand() % 50) / -10.0);
                particles[i].obj_set_y_vel(0);
                break;
            case 3:
                particles[i].obj_init(graphic, ren, start_x, start_y + 17 + rand() % 34, start_w, start_h);
                particles[i].obj_set_x_vel(-4 + (rand() % 50) / -10.0);
                particles[i].obj_set_y_vel(0);
                break;
            }
        }
    }
}
void ParticleManager::pm_update()
{

    int max_parts = MAX_PARTS;

    if (part_type == PART_TYPE_BLOW)
    {
        max_parts = MAX_PARTS_BLOW;
        for (int i = 0; i < max_parts; i++)
        {
            particles[i].obj_update_blow();
        }
    }
}

void ParticleManager::pm_render(SDL_Renderer *ren)
{
    int max_parts = MAX_PARTS;

    if (part_type == PART_TYPE_BLOW)
    {
        max_parts = MAX_PARTS_BLOW;
        for (int i = 0; i < max_parts; i++)
        {
            particles[i].obj_render_blow(ren);
        }
    }
}
