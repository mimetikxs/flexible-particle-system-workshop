#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);    
    
    // setup emitters
    // ...

    // setup forces
    // ...

    // setup particle system and add emitters and forces
    // ...
    
    // setup gui
    gui.setup();

    // ...      

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));    

    // ...

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));

    // ...

    gui.minimizeAll(); //< gui begins collapsed

    // setup presets
    // ...
}


void ofApp::update()
{
    // ...
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
        // ...

        // draw forces
        ofSetColor(255, 0, 0);
        // ...
    }
                    
    ofPopStyle();

    // draw gui
    gui.draw();
    // ...

    // draw info
    string info = ofToString(particleSystem.getParticleData().countAlive) + "/" + ofToString(particleSystem.getParticleData().count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case '1':        
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case 'd':
        bDrawDebug = !bDrawDebug;
        break;
    default:
        break;
    }
}


//void ofApp::savePreset()
//{
//    gui.saveToFile("preset-" + ofToString(presetIndex) + ".xml");
//}


//void ofApp::loadPreset()
//{
//    gui.loadFromFile("preset-" + ofToString(presetIndex) + ".xml");
//}
