#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "EmitterRect.h"
#include "ForceWind.h"
#include "ForceAttraction.h"
#include "Forcefield.h"
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
    
    // gui
    ofxPanel gui;
    bool bDrawDebug = false;

    // presets
    ofxPanel guiPresets;
    ofParameter<int> presetIndex;
    ofParameter<void> toggleSave;
    ofParameter<void> toggleLoad;

    void savePreset();
    void loadPreset();
};
