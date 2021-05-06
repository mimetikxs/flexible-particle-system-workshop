#pragma once
#include "ofMain.h"

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();
    void keyPressed(int key);

    vec2 position;
    vec2 velocity;
    vec2 accel;

    float friction;
    float timestep;
};
