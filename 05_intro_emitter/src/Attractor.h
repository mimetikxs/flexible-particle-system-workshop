#pragma once
#include "ofMain.h"
#include "Particle.h"

using namespace glm;

class Attractor
{
public:

    vec2 pos;

    ofParameterGroup parameters;
    ofParameter<float> strength;
    ofParameter<float> mass;
    ofParameter<float> minDistance;
    ofParameter<float> maxDistance;    

    void setup(string name, vec2 pos);    
    void draw();
    vec2 getForce(Particle& p);

};