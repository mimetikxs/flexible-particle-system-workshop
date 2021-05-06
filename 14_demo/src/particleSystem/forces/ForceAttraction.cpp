#include "ForceAttraction.h"

void ForceAttraction::setup(string name)
{
    parameters.setName(name);
    parameters.add (x.set(           "x",        0, 0, ofGetWidth()));
    parameters.add( y.set(           "y",        0, 0, ofGetHeight()));
    parameters.add( strength.set(    "strength", 0.4, -10.0, 10.0));
    parameters.add( mass.set(        "mass",     1.0, 0.1, 100.0));
    parameters.add( minDistance.set( "min dist", 50.0, 0.0, 500.0));
    parameters.add( maxDistance.set( "max dist", 600.0, 0.0, 2000.0));
}


void ForceAttraction::draw()
{
    vec2 pos = vec2(x, y);

    ofPushStyle();
    ofNoFill();
    ofDrawLine(pos + vec2(-10, 0), pos + vec2(10, 0));
    ofDrawLine(pos + vec2(0, -10), pos + vec2(0, 10));
    ofPopStyle();

    ofDrawBitmapString(parameters.getName(), pos.x + 5, pos.y + 15);
}


void ForceAttraction::applyForce(Particle& p)
{
    vec2 dir = p.pos - vec2(x, y);
    float dist = clamp(length(dir), minDistance.get(), maxDistance.get());
    float forceStrength = (strength * mass * p.mass) / dist;

    dir /= dist;

    p.applyForce(-forceStrength * dir);
}
