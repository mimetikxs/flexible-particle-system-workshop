#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "EmitterRect.h"
#include "ForceWind.h"
#include "RenderPoints.h"
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

    // render
    RenderPoints renderer;
    
    // gui
    ofxPanel gui;
    bool bDrawGui = true;
    bool bDrawDebug = false;
};
