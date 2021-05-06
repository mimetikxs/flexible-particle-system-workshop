#pragma once
#include "ofMain.h"
#include "Particle.h"
//#include "Force.h"

using namespace glm;

class ForceAttraction
{
public:

    vec2 pos;

    ofParameterGroup parameters;
    ofParameter<float> strength;
    ofParameter<float> mass;
    ofParameter<float> minDistance;
    ofParameter<float> maxDistance;    

    void setup(string name);    
    void applyForce(Particle& p);
    void draw();

};