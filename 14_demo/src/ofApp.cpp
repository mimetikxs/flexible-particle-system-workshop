#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);    
    
    // setup emitter
    emitter.setup("emitter");

    // setup forces
    forceWind.setup("wind");
    
    forceAttraction.setup("attraction");
    
    forcefield.setup("forcefield");
    forcefield.setupGrid(ofGetWidth(), ofGetHeight(), 20);

    // setup particle system and add emitters and forces
    particleSystem.setup(ofGetWidth(), ofGetHeight(), 10000);
    particleSystem.addEmitter(&emitter);
    particleSystem.addForce(&forceWind);
    particleSystem.addForce(&forceAttraction);
    particleSystem.addForce(&forcefield);

    // setup rendering
    renderLines.setup("renderer lines");

    fboLines.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F);
    
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
    gui.add(forcefield.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155));
    gui.setDefaultBorderColor(ofColor(155));

    gui.add(renderLines.parameters);
    gui.add(trailsOpacity.set("trails opacity", 0, 0, 1));

    gui.minimizeAll();

    // setup presets
    presets.setup(&gui, 5);
    presets.applyPreset(0);
}


void ofApp::update()
{
    // update forcefield 
    forcefield.updateNoise();

    // update particles first
    particleSystem.update();

    // then update renderer
    renderLines.update( particleSystem.getParticleData() );
}


void ofApp::draw()
{
    // draw particles using lines renderer
    fboLines.begin();
    {
        ofSetColor(0,0,0, (1 - trailsOpacity) * 255);
        ofDrawRectangle(0, 0, fboLines.getWidth(), fboLines.getHeight());

        renderLines.draw();
    }
    fboLines.end();
    fboLines.draw(0, 0);

    if (bDrawDebug)
    {
        drawDebug();
    }

    // draw gui
    if (bDrawGui)
    {
        gui.draw();

        presets.draw();

        // draw info
        string info = ofToString(particleSystem.getParticleData().countAlive) + "/" + ofToString(particleSystem.getParticleData().count);
        ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
        ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate(), 0), ofGetWidth() - 40, ofGetHeight() - 30); // fps
    }
}


void ofApp::drawDebug()
{
    ofPushStyle();

    // draw emitters
    ofSetColor(0, 255, 0);
    emitter.draw();

    // draw forces
    ofSetColor(255, 0, 0);
    forceWind.draw();
    forceAttraction.draw();
    forcefield.draw();

    ofPopStyle();
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case '1':
        presets.applyPreset(0);
        break;
    case '2':
        presets.applyPreset(1);
        break;
    case '3':
        presets.applyPreset(2);
        break;
    case '4':
        presets.applyPreset(3);
        break;
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