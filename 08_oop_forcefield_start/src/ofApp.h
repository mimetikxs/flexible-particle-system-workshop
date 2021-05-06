#pragma once
#include "ofMain.h"
#include "ParticleSystem.h"
#include "Emitter.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();
    void keyPressed(int key);

    ParticleSystem particleSystem;

    Emitter emitter;
            
    // gui
    ofxPanel gui;
    bool bDrawDebug = true;
};
