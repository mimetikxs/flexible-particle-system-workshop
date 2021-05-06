#pragma once
#include "ofMain.h"
#include "ParticleData.h"

class Emitter
{
public:

    ofParameter<float> emitRate;
    ofParameterGroup parameters;

    // particles will be emited with this parameters
    float mass = 1;
    float massVariation = 1; // 1 = no variation
    float life = 1;
    float lifeVariation = 1; // 1 = no variation

    virtual void setup(string name) = 0;
    virtual void emit(ParticleData& pd) = 0;
    virtual void draw() = 0;
};
