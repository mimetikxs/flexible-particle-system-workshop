#pragma once
#include "ofMain.h"
#include "Particle.h"

using namespace glm;

class ForceAttractor
{
public:

    vec2 pos;

    ofParameterGroup parameters;
    ofParameter<float> strength;
    ofParameter<float> mass;
    ofParameter<float> minDistance;
    ofParameter<float> maxDistance;    

    void setup(string name);    
    void draw();
    void applyForce(Particle& p);

};