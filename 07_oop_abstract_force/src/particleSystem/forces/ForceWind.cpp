#include "ForceWind.h"


void ForceWind::setup(string name)
{
    parameters.setName(name);
    parameters.add( force.set("force", vec2(0.0), vec2(-2.0), vec2(2.0)));
}


void ForceWind::applyForce(Particle& p)
{
    p.applyForce(force);
}



void ForceWind::draw()
{
}