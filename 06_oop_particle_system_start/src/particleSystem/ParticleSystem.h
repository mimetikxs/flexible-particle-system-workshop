#pragma once
#include "ofMain.h"
#include "ParticleData.h"
#include "Emitter.h"
#include "ForceAttractor.h"

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

    // objects are created externally (eg: ofApp)
    // we need to pass pointers to reference the external objects 
    void addEmitter(Emitter* emitter);
    void addForce(ForceAttractor* force);

    const ParticleData& getParticleData();

private:

    // system boundaries
    float width;
    float height;

    // particles
    ParticleData particleData;

    // arrays of pointers
    // we need to store pointers to reference the external objects 
    vector<Emitter*>        emitters;
    vector<ForceAttractor*> forces;
};

