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

    // setup forces
    forceWind.setup("wind");
    forceWind.force = vec2(0, 0.046);

    forceAttraction.setup("attraction");
    forceAttraction.strength = 0;
    forceAttraction.pos = vec2(ofGetWidth() / 2, ofGetHeight() / 2);

    // setup particle system and add emitters and forces
    particleSystem.setup(ofGetWidth(), ofGetHeight(), 50000);
    particleSystem.addEmitter(&emitter);
    particleSystem.addForce(&forceWind);
    particleSystem.addForce(&forceAttraction);
    particleSystem.life = 204;

    // setup renderer
    renderer.setup("renderer lines");

    fboTrails.allocate(ofGetWidth(), ofGetHeight());
    
    // setup gui
    gui.setup();

    gui.add(particleSystem.parameters);      

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));    

    gui.add(emitter.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));

    gui.add(forceWind.parameters);
    gui.add(forceAttraction.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155));
    gui.setDefaultBorderColor(ofColor(155));

    gui.add(renderer.parameters);
    gui.add(trailsOpacity.set("trails opacity", 0, 0, 1));

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
    fboTrails.begin();
    {
        ofSetColor(0,0,0, (1 - trailsOpacity) * 255);
        ofDrawRectangle(0, 0, fboTrails.getWidth(), fboTrails.getHeight());

        renderer.draw();
    }
    fboTrails.end();
    fboTrails.draw(0, 0);

    if (bDrawDebug)
    {
        // draw emitters
        ofSetColor(0, 255, 0);
        emitter.draw();

        // draw forces
        ofSetColor(255, 0, 0);
        forceWind.draw();
        forceAttraction.draw();
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
