#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Force.h"

using namespace glm;

class ForceAttraction : public Force
{
public:

    vec2 pos;

    ofParameter<float> strength;
    ofParameter<float> mass;
    ofParameter<float> minDistance;
    ofParameter<float> maxDistance;    

    void setup(string name) override;    
    void applyForce(Particle& p) override;
    void draw() override;

};