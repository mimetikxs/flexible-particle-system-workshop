#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "ForceAttractor.h"
#include "Emitter.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();

    // all the simulation logic is now inside this class
    ParticleSystem particleSystem;

    // we store the attractor and the emitter here
    ForceAttractor attractor;
    Emitter emitter;
        
    // gui
    ofxPanel gui;
};
