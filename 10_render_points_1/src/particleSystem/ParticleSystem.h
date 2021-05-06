#pragma once
#include "ofMain.h"
#include "ParticleData.h"
#include "Emitter.h"
#include "Force.h"

class ParticleSystem
{
public:

    ofParameterGroup parameters;
    ofParameter<float> timeStep;
    ofParameter<float> friction;
    ofParameter<float> life;
    ofParameter<float> lifeVariation;
    ofParameter<float> mass;
    ofParameter<float> massVariation; 
    
    void setup(float width, float height, int numParticles);
   
    void update();

    void addEmitter(Emitter* emitter);
    void addForce(Force* force);

    const ParticleData& getParticleData();

private:

    // system boundaries
    float width;
    float height;

    ParticleData     particleData;

    vector<Emitter*> emitters;
    vector<Force*>   forces;
};

