#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);    
    
    // setup emitters
    emitter.setup("emitter");

    // setup forces
    forceWind.setup("wind");

    forceAttraction.setup("attraction");
    forceAttraction.pos = vec2(ofGetWidth(), ofGetHeight()) / 2;

    forcefield.setup("forcefield");
    forcefield.setupGrid(ofGetWidth(), ofGetHeight(), 19);
    forcefield.updateNoise();

    // setup particle system and add emitters and forces
    particleSystem.setup(ofGetWidth(), ofGetHeight(), 5000);
    particleSystem.addEmitter(&emitter);
    particleSystem.addForce(&forceWind);
    particleSystem.addForce(&forceAttraction);
    particleSystem.addForce(&forcefield);
    
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

    gui.minimizeAll();

    // setup presets
    guiPresets.setup("presets");
    guiPresets.add(presetIndex.set("index", 0, 0, 3));
    guiPresets.add(toggleLoad.set("<-- LOAD"));
    guiPresets.add(toggleSave.set("<-- SAVE"));
    guiPresets.setPosition(ofGetWidth()-220, 20);

    toggleLoad.addListener(this, &ofApp::loadPreset);
    toggleSave.addListener(this, &ofApp::savePreset);
}


void ofApp::update()
{
    forcefield.updateNoise();

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

        // draw forces
        ofSetColor(255, 0, 0);
        forceWind.draw();
        forceAttraction.draw();
        forcefield.draw();
    }
                    
    ofPopStyle();

    // draw gui
    gui.draw();
    guiPresets.draw();

    // draw info
    string info = ofToString(particleSystem.getParticleData().countAlive) + "/" + ofToString(particleSystem.getParticleData().count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case '1':
        presetIndex = 0;
        loadPreset();
        break;
    case '2':
        presetIndex = 1;
        loadPreset();
        break;
    case '3':
        presetIndex = 2;
        loadPreset();
        break;
    case '4':
        presetIndex = 3;
        loadPreset();
        break;
    case 'd':
        bDrawDebug = !bDrawDebug;
        break;
    default:
        break;
    }
}


void ofApp::savePreset()
{
    gui.saveToFile("preset-" + ofToString(presetIndex) + ".xml");
}


void ofApp::loadPreset()
{
    gui.loadFromFile("preset-" + ofToString(presetIndex) + ".xml");
}
