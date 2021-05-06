#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);

    // allocate particles once
    // ...
    
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
    gui.add(life.set("life", 50, 1, 400));
    gui.add(emitRate.set("emit rate", 10, 0, 100));

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));
    
    gui.add(attractor1.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));
    
    gui.add(attractor2.parameters);
}


void ofApp::emitParticles(int count)
{
    //int available = maxNumParticles - particles.size();
    //int maxNewparticles = MIN(count, available);

    //for (int i = 0; i < maxNewparticles; i++)
    //{
    //    Particle p;
    //    p.setup(
    //        vec2(ofRandomWidth(), ofRandomHeight()),    // position 
    //        life                                        // life
    //    );
    //    particles.push_back(p);
    //}
}


void ofApp::update()
{
    // emit 
    emitParticles(emitRate);

    // update
    //for (int i = 0; i < particles.size(); i++)
    //{
    //    Particle& p = particles[i];

    //    // accumulate all forces acting over the particle
    //    p.applyForce(attractor1.getForce(p));
    //    p.applyForce(attractor2.getForce(p));

    //    // update 
    //    p.update(friction, timestep);

    //    // remove particle if dead
    //    if (p.elapsedLife > p.maxLife)
    //    {
    //        particles.erase(particles.begin() + i);
    //        i -= 1;
    //    }
    //}
}


void ofApp::draw()
{ 
    ofPushStyle();    
        
    // draw particles
    ofSetColor(255);
    //for (int i = 0; i < particles.size(); i++)
    //{
    //    ofDrawCircle(particles[i].pos, particles[i].mass);
    //}

    // draw attractors
    ofSetColor(0, 255, 0);
    attractor1.draw();
    ofSetColor(255, 0, 0);
    attractor2.draw();
                
    ofPopStyle();

    // draw gui
    gui.draw();

    // draw info
    string info = ofToString(particleData.countAlive) + "/" + ofToString(particleData.count);
    ofDrawBitmapStringHighlight(info, 20, ofGetHeight() - 30);
}




