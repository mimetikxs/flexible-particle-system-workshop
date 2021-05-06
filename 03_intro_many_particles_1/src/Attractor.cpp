#include "Attractor.h"

void Attractor::setup(string name)
{
    parameters.setName(name);
    parameters.add( strength.set(    "strength", 0.4, -10.0, 10.0));
    parameters.add( mass.set(        "mass",     1.0, 0.1, 100.0));
    parameters.add( minDistance.set( "min dist", 50.0, 0.0, 500.0));
    parameters.add( maxDistance.set( "max dist", 600.0, 0.0, 2000.0));
}


void Attractor::draw()
{
    ofPushStyle();
    ofNoFill();
    ofDrawLine(pos + vec2(-10, 0), pos + vec2(10, 0));
    ofDrawLine(pos + vec2(0, -10), pos + vec2(0, 10));
    ofPopStyle();

    // draw info
    ofDrawBitmapString(parameters.getName(), pos.x + 5, pos.y + 15);
}


vec2 Attractor::getForce(Particle& p)
{
    vec2 dir = p.pos - pos;
    float dist = clamp(length(dir), minDistance.get(), maxDistance.get());
    float forceStrength = (strength * mass * p.mass) / dist;

    dir /= dist;

    return (-forceStrength * dir);
}
