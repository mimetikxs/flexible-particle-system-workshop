#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);

    // allocate particles once
    particleData.generate(maxNumParticles);
    
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
    // range of dead particles
    int fist = particleData.countAlive;
    int last = MIN(fist + count, particleData.count);

    for (int i = fist; i < last; i++)
    {
        particleData.particles[i].setup(
            vec2(ofRandomWidth(), ofRandomHeight()),    // position 
            life                                        // life
        );
        particleData.wake(i);
    }
}


void ofApp::update()
{
    // emit 
    emitParticles(emitRate);

    // update
    for (int i = 0; i < particleData.countAlive; i++)
    {
        Particle& p = particleData.particles[i];

        // accumulate all forces acting over the particle
        p.applyForce(attractor1.getForce(p));
        p.applyForce(attractor2.getForce(p));

        // update 
        p.update(friction, timestep);        

        // WARNING: 
        // we can't kill particles while iterating
        // the swaped particle won't be updated
        //if (p.elapsedLife > p.maxLife)
        //{
        //    particleData.kill(i);
        //}
    }

    // kill particles
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




