#include "Attractor.h"

void Attractor::setup(string name)
{
    // ...
}


void Attractor::draw()
{
    ofPushStyle();
    ofNoFill();
    ofDrawLine(pos + vec2(-10, 0), pos + vec2(10, 0));
    ofDrawLine(pos + vec2(0, -10), pos + vec2(0, 10));
    ofPopStyle();

    ofDrawBitmapString(parameters.getName(), pos.x + 5, pos.y + 15);
}


vec2 Attractor::getForce(Particle& p)
{
    // ...

    return vec2();
}
