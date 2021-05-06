//
// A virtual class that serves as the base for all the forces.
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Force
{
public:

    ofParameterGroup parameters;

    virtual void setup(string name) = 0;

    virtual void applyForce(Particle& p) = 0;

    virtual void draw() = 0;
};
