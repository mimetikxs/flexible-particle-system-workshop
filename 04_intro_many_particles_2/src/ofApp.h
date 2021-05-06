#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Attractor.h"
#include "ParticleData.h"
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
    ofParameter<float> emitRate;

    // particles
    const int maxNumParticles = 1000;
    ParticleData particleData;

    void emitParticles(int count);
    
    // forces
    Attractor attractor1;
    Attractor attractor2;
    
    // gui
    ofxPanel gui;
};
