#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "EmitterRect.h"
#include "ForceWind.h"
#include "ForceAttraction.h"
#include "Forcefield.h"
#include "RenderLines.h" 
#include "Presets.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();
    void keyPressed(int key);

    // particle system
    ParticleSystem particleSystem;
    EmitterRect emitter;
    ForceWind forceWind;
    ForceAttraction forceAttraction;
    Forcefield forcefield;

    // render
    RenderLines renderLines;

    ofFbo fboLines;
    ofParameter<float> trailsOpacity;

    // presets
    Presets presets;
    
    // gui
    ofxPanel gui;
    bool bDrawGui = true;
    bool bDrawDebug = false;

    void drawDebug();
};
