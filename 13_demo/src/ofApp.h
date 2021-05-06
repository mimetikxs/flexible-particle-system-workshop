#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "EmitterRect.h"
#include "ForceWind.h"
#include "ForceAttraction.h"
#include "RenderPoints.h"
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

    // render
    RenderLines renderLines;
    RenderPoints renderPoints;

    ofFbo fboLines;
    ofFbo fboPoints;
    ofParameter<float> trailsOpacity;

    // presets
    Presets presets;
    
    // gui
    ofxPanel gui;
    bool bDrawGui = true;
    bool bDrawDebug = false;

    void drawDebug();
};
