#pragma once
#include "ofMain.h"
#include "ParticleData.h"

class Render
{
public:

    ofParameterGroup parameters;

    virtual void setup(string name) = 0;

    virtual void update(const ParticleData& pd) = 0;

    virtual void draw() = 0;
};
