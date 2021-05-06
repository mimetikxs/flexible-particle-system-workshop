#include "ofApp.h"


void drawArrow(vec2 tail, vec2 head)
{
    ofDrawArrow(vec3(tail, 0), vec3(head, 0), 5);
}


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);

    position.x = ofGetWidth() / 2;
    position.y = ofGetHeight() / 2;

    velocity.x = 0;
    velocity.y = 0;

    friction = 0;
    timestep = 1;
}


void ofApp::update()
{
    accel = vec2(0);

    // calculate force (apply an impulse)
    if (ofGetMousePressed())
    {
        vec2 mouse = vec2(ofGetMouseX(), ofGetMouseY());
        vec2 diff = mouse - position;
        
        accel = normalize(diff) * 0.1;
    }

    // move simulation forward (euler integration)
    velocity += accel * timestep;
    velocity *= (1 - friction);
    position += velocity * timestep;

    // handle out of bounds
    if (position.x > ofGetWidth()) position.x = 0;
    if (position.x < 0) position.x = ofGetWidth();
    if (position.y > ofGetHeight()) position.y = 0;
    if (position.y < 0) position.y = ofGetHeight();
}


void ofApp::draw()
{ 
    ofPushStyle();

    // draw a circle in the position
    ofDrawCircle(position, 20);
    
    // draw position vector
    ofSetColor(0, 0, 255);
    drawArrow(vec2(0), position); 
    
    // draw position axis
    ofSetColor(0, 0, 255, 100);
    ofDrawLine(vec2(0, position.y), position); // x-axis
    ofDrawLine(vec2(position.x, 0), position); // y-axis
    
    // draw velocity vector
    ofSetColor(255, 0, 0);
    drawArrow(position, position + velocity * 50); 

    // draw accel vector
    if (ofGetMousePressed())
    {
        ofSetColor(0, 255, 0);
        drawArrow(position, position + accel * 500);
    }
    
    ofPopStyle();

    ofDrawBitmapString("friction: " + ofToString(friction, 2), 20, 20);
    ofDrawBitmapString("timestep: " + ofToString(timestep, 2), 20, 40);
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case OF_KEY_UP:
        timestep += 0.1;
        timestep = MIN(timestep, 3);
        break;
    case OF_KEY_DOWN:
        timestep -= 0.1;
        timestep = MAX(timestep, 0.1);
        break;
    case 'f':
        friction = (friction == 0) ? 0.02 : 0;
        break;
    default:
        break;
    }
}

