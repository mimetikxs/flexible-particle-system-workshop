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

    ParticleSystem particleSystem;

    ForceAttractor attractor;
    Emitter emitter;
        
    // gui
    ofxPanel gui;
};
