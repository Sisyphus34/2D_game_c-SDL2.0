
#include "TextureManager.h"
#include "Particle.h"

Particle::Particle() {}
Particle::~Particle() {}

void Particle::particle_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int start_width, int start_height)
{

    x_pos = (float)start_x;
    y_pos = (float)start_y;

    width = (float)start_width;
    height = (float)start_height;

    isDead = false;

    particle_texture = TextureManager::LoadTexture(graphic, ren);
}

void Particle::particle_update()
{
    x_pos += x_vel;
    y_pos += y_vel;

    y_vel += 9.8 * 100.0 / 36000.0; //100 px/meter

    if (lifetime > 0)
    {
        particle_rect.x = (int)x_pos;
        particle_rect.y = (int)y_pos;
        particle_rect.w = (int)width / 2 + width * (int)(10 * lifetime / 100);
        particle_rect.h = (int)height / 2 + height * (int)(10 * lifetime / 100);
    }
    lifetime -= 1;
}
void Particle::particle_render(SDL_Renderer *ren)
{
    if (lifetime > 0)
    {
        SDL_RenderCopy(ren, particle_texture, NULL, &particle_rect);
    }
}
void Particle::particle_quit()
{
    SDL_DestroyTexture(particle_texture);
    // SDL_DestroyRenderer(particle_renderer);
}

int Particle::particle_get_x_vel()
{
    return (int)x_vel;
}
void Particle::particle_set_x_vel(float x_val)
{
    x_vel = x_val;
}
int Particle::particle_get_y_vel()
{
    return (int)y_vel;
}
void Particle::particle_set_y_vel(float y_val)
{
    y_vel = y_val;
}

int Particle::particle_get_x_pos()
{
    return (int)x_pos;
}
void Particle::particle_set_x_pos(int new_x)
{
    x_pos = new_x;
}

int Particle::particle_get_y_pos()
{
    return (int)y_pos;
}
void Particle::particle_set_y_pos(int new_y)
{
    y_pos = new_y;
}
int Particle::particle_get_lifetime()
{
    return lifetime;
}

void Particle::particle_set_lifetime(int new_lifetime)
{
    lifetime = new_lifetime;
}

bool Particle::particle_get_isDead()
{
    return isDead;
}

void Particle::particle_set_isDead(bool died)
{
    isDead = died;
}

ParticleManager::ParticleManager() {}
ParticleManager::~ParticleManager() {}

void ParticleManager::pm_init(const char *graphic, SDL_Renderer *ren, int start_x, int start_y, int start_w, int start_h)
{
    srand(5);

    int max_parts = MAX_PARTS;

    for (int i = 0; i < max_parts; i++)
    {
        particles[i].particle_init(graphic, ren, start_x, start_y, start_w, start_h);
        particles[i].particle_set_x_vel(2.0 - (rand() % 50) / 10.0);
        particles[i].particle_set_y_vel(0 - (rand() % 50) / 10.0);
        particles[i].particle_set_lifetime(30 + (rand() % 10));
    }
}
void ParticleManager::pm_update()
{

    int max_parts = MAX_PARTS;

    for (int i = 0; i < max_parts; i++)
    {
        particles[i].particle_update();
    }
}

void ParticleManager::pm_render(SDL_Renderer *ren)
{
    int max_parts = MAX_PARTS;

    for (int i = 0; i < max_parts; i++)
    {
        particles[i].particle_render(ren);
    }
}
void ParticleManager::pm_quit()
{
    int max_parts = MAX_PARTS;

    for (int i = 0; i < max_parts; i++)
    {
        if (particles[i].particle_get_lifetime() < 0)
        {
            particles[i].particle_quit();
            std::cout << "Destroyed texture for particle " << i << std::endl;
        }
    }
}
