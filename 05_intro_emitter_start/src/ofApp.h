#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Attractor.h"
#include "ParticleData.h"
//#include "Emitter.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();

    // global parameters
    ofParameter<float> friction;
    ofParameter<float> timestep;
    ofParameter<float> life;    
    ofParameter<float> mass;
    //ofParameter<float> lifeVariation;
    //ofParameter<float> massVariation;

    // particles
    const int maxNumParticles = 5000;
    ParticleData particleData;
    
    // forces
    Attractor attractor1;
    Attractor attractor2;

    // emitters
    // ...
    
    // gui
    ofxPanel gui;
};
