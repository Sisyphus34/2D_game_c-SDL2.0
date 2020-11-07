#pragma once

class Particle
{
public:
    Particle();
    ~Particle();

    void drawParticle();
    void updateParticle();

    int x;
    int y;

    int x_vel;
    int y_vel;

    float lifetime;
};