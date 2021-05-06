#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);    
    
    // setup forces
    // ...

    // setup emitters
    emitter.setup("emitter");
    emitter.width = 1024;
    emitter.height = 768;
    emitter.emitRate = 20;

    // allocate particles once
    particleSystem.setup(ofGetWidth(), ofGetHeight(), 5000);
    particleSystem.addEmitter(&emitter);
    // ...
    
    // setup gui
    gui.setup();

    gui.add(particleSystem.parameters);      

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));    

    gui.add(emitter.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));

    // ...
}


void ofApp::update()
{
    // ...

    particleSystem.update();
}


void ofApp::draw()
{ 
    ofPushStyle();    
        
    // draw particles
    ofSetColor(255);
    for (int i = 0; i < particleSystem.getParticleData().countAlive; i++)
    {
        auto& p = particleSystem.getParticleData().particles[i];
        ofDrawCircle(p.pos, p.mass);
    }

    if (bDrawDebug)
    {
        // draw emitters
        ofSetColor(0, 255, 0);
        emitter.draw();

        // draw forcefield
        ofSetColor(255, 0, 0);
        // ...
    }
                    
    ofPopStyle();

    // draw gui
    gui.draw();

    // draw info
    string info = ofToString(particleSystem.getParticleData().countAlive) + "/" + ofToString(particleSystem.getParticleData().count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case 'd':
        bDrawDebug = !bDrawDebug;
        break;
    default:
        break;
    }
}


