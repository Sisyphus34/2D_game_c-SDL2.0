#pragma once

class Particle
{
public:
    Particle();
    ~Particle();

    // if the lifetime has not ended, draw whatever is
    // appropriate for that particle
    void drawParticle();

    /**update velocity and possibly add in gravity
     * at every time change we want to update the position
     * and the lifetime(probably just decrement the lifetime)
     * 
     */

    void updateParticle();

    int x;
    int y;

    int x_vel;
    int y_vel;

    float lifetime;
};