#pragma once
#include "ofMain.h"
#include "Particle.h"
#include "Attractor.h"
#include "ofxGui.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();
    void keyPressed(int key);

    ofParameter<float> friction;
    ofParameter<float> timestep;

    Particle particle;    

    Attractor attractor1;
    Attractor attractor2;
       
    ofxPanel gui;

    std::deque<vec2> trail;
};
