#include "Particle.h"


void Particle::setup(vec2 position, float _mass)
{
    pos = position;
    vel *= 0;
    accel *= 0;
    mass = _mass;
}


void Particle::applyForce(vec2 force)
{
    accel += force / mass;
}


void Particle::update(float friction, float timestep)
{
    // move simulation forward in time
    vel += accel * timestep;
    vel *= (1 - friction);
    pos += vel * timestep;

    // reset net force accumulator
    accel *= 0;
}
