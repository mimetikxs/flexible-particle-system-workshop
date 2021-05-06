#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);    
    
    // setup emitter
    emitter.setup("emitter");
    emitter.width = ofGetWidth();
    emitter.height = 20;
    emitter.emitRate = 45;

    // setup force
    forceWind.setup("wind");
    forceWind.force = vec2(0, 0.046);

    // setup particle system and add emitters and forces
    particleSystem.setup(ofGetWidth(), ofGetHeight(), 50000);
    particleSystem.addEmitter(&emitter);
    particleSystem.addForce(&forceWind);
    particleSystem.life = 204;

    // setup renderer
    renderer.setup("renderer points");
    
    // setup gui
    gui.setup();

    gui.add(particleSystem.parameters);      

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));    

    gui.add(emitter.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));

    gui.add(forceWind.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155));
    gui.setDefaultBorderColor(ofColor(155));

    gui.add(renderer.parameters);

    gui.minimizeAll();
}


void ofApp::update()
{
    // update particles first
    particleSystem.update();

    // then update renderer
    renderer.update( particleSystem.getParticleData() );
}


void ofApp::draw()
{
    ofPushStyle();
    ofSetColor(255);

    // draw particles
    renderer.draw();    

    if (bDrawDebug)
    {
        // draw emitters
        ofSetColor(0, 255, 0);
        emitter.draw();

        // draw forces
        ofSetColor(255, 0, 0);
        forceWind.draw();
    }

    ofPopStyle();

    // draw gui
    if (bDrawGui)
    {
        gui.draw();
    }

    // draw info
    string info = ofToString(particleSystem.getParticleData().countAlive) + "/" + ofToString(particleSystem.getParticleData().count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate(), 0), ofGetWidth() - 40, ofGetHeight() - 30); // fps
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case 'd':
        bDrawDebug = !bDrawDebug;
        break;
    case 'g':
        bDrawGui = !bDrawGui;
        break;
    default:
        break;
    }
}
