#pragma once
#include "ofMain.h"
// ...

using namespace glm;

class ofApp : public ofBaseApp
{
public:

	void setup();
	void update();
    void draw();
    void keyPressed(int key);

    float friction = 0;
    float timestep = 1;

    // ...
};
