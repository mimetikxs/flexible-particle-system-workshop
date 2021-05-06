#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);

    // allocate particles once
    particleData.generate(maxNumParticles);
    
    // setup forces
    attractor1.setup("attractor 1", vec2(300,400));
    attractor1.strength = 8;

    attractor2.setup("attractor 2", vec2(700,300));
    attractor2.strength = 9;

    // setup emitters
    // ...

    // setup gui
    gui.setup();

    gui.add(timestep.set("timestep", 1, 0, 2));
    gui.add(friction.set("friction", 0, 0, 0.2));
    gui.add(life.set("life", 100, 1, 1000));
    //gui.add(lifeVariation.set("life variation", 1, 1, 10));
    gui.add(mass.set("mass", 1, 0.001, 10));
    //gui.add(massVariation.set("mass variation", 1, 1, 10));

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));    

    // ...

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));

    gui.add(attractor1.parameters);
    gui.add(attractor2.parameters);
}


void ofApp::update()
{
    // ------------
    // emitters 
    // ------------
    
    // pass down global parameters (same for all emitters)
    // ...

    // emit

    // update
    for (int i = 0; i < particleData.countAlive; i++)
    {
        Particle& p = particleData.particles[i];

        // accumulate all forces acting over the particle
        p.applyForce( attractor1.getForce(p));
        p.applyForce( attractor2.getForce(p));

        // update 
        p.update(friction, timestep);    
    }

    // kill 
    for (int i = 0; i < particleData.countAlive; i++)
    {
        Particle& p = particleData.particles[i];
        if (p.elapsedLife > p.maxLife)
        {
            particleData.kill(i);
        }
    }
}


void ofApp::draw()
{ 
    ofPushStyle();    
        
    // draw particles
    ofSetColor(255);
    for (int i = 0; i < particleData.countAlive; i++)
    {
        Particle& p = particleData.particles[i];
        ofDrawCircle(p.pos, p.mass);
    }

    // draw emitters
    ofSetColor(0, 255, 0);
    // ...
       
    // draw attractors
    ofSetColor(255, 0, 0);
    attractor1.draw();
    attractor2.draw();
                    
    ofPopStyle();

    // draw gui
    gui.draw();

    // draw info
    string info = ofToString(particleData.countAlive) + "/" + ofToString(particleData.count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}




