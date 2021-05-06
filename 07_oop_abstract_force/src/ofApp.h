#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "ForceAttraction.h"
#include "ForceWind.h"
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

    ForceAttraction attractor;
    ForceWind wind;

    Emitter emitter;
        
    // gui
    ofxPanel gui;
};
