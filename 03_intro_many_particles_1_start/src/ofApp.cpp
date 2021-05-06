#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);
    
    // setup forces
    attractor1.setup("attractor 1");
    attractor1.pos = vec2(300, 400);
    attractor1.strength = 8;

    attractor2.setup("attractor 2");
    attractor2.pos = vec2(700, 300);
    attractor2.strength = 9;

    // setup gui
    gui.setup();
    gui.add(timestep.set("timestep", 1, 0, 2));
    gui.add(friction.set("friction", 0, 0, 0.2));
    // ...

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));
    
    gui.add(attractor1.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));
    
    gui.add(attractor2.parameters);
}


void ofApp::emitParticles(int count)
{
    // ...
}


void ofApp::update()
{
    // emit particles
    // ...

    // iterate over all particles:
    
        // accumulate all forces acting over the particle
        // ...

        // update particle
        // ...
        
        // remove particle if dead
        // ...
}


void ofApp::draw()
{ 
    ofPushStyle();    
        
    // draw particles
    ofSetColor(255);
    // ...

    // draw attractors
    ofSetColor(0, 255, 0);
    attractor1.draw();
    ofSetColor(255, 0, 0);
    attractor2.draw();
                
    ofPopStyle();

    // draw gui
    gui.draw();

    // draw info
    string info = ofToString(particles.size()) + "/" + ofToString(maxNumParticles);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}




