#include "ofApp.h"


void drawArrow(vec2 tail, vec2 head)
{
    ofDrawArrow(vec3(tail, 0), vec3(head, 0), 5);
}


void ofApp::setup()
{
    ofBackground(0);
    ofSetVerticalSync(true);

    particle.setup( vec2(500,0) );

    // attractors
    attractor1.setup("attractor 1");
    attractor1.pos = vec2(300, 400);
    attractor1.strength = 8;    
    
    attractor2.setup("attractor 2");
    attractor2.pos = vec2(700, 300);
    attractor2.strength = 9;

    // setup gui
    gui.setup();
    gui.add(friction.set("friction", 0, 0, 0.2));
    gui.add(timestep.set("timestep", 1, 0, 2));

    gui.setDefaultHeaderBackgroundColor(ofColor(0, 155, 0));
    gui.setDefaultBorderColor(ofColor(0, 155, 0));
    
    gui.add(attractor1.parameters);

    gui.setDefaultHeaderBackgroundColor(ofColor(155, 0, 0));
    gui.setDefaultBorderColor(ofColor(155, 0, 0));
    
    gui.add(attractor2.parameters);
}


void ofApp::update()
{
    // accumulate all forces acting over the particle (net force)
    particle.applyForce( attractor1.getForce(particle) );
    particle.applyForce( attractor2.getForce(particle) );

    // update position
    particle.update(friction, timestep);

    // add new pos to trail
    if (ofGetFrameNum() % 10 == 0)
    {
        trail.push_back(particle.pos);
        if (trail.size() > 500)
        {
            trail.pop_front();
        }
    }    
}



void ofApp::draw()
{ 
    ofPushStyle();

    // draw attractors
    ofSetColor(0, 255, 0);
    attractor1.draw();
    ofSetColor(255, 0, 0);
    attractor2.draw();

    // draw trail
    ofSetColor(50);
    ofNoFill();
    ofBeginShape();    
    for (auto& p : trail) 
    {
        ofVertex(p);
    }
    ofVertex(particle.pos);
    ofEndShape();
    ofFill();
    
    // draw the particle
    ofSetColor(255);
    ofDrawCircle(particle.pos, 10);
    // draw velocity vector
    drawArrow(particle.pos, particle.pos + particle.vel * 20);

    // draw attraction vectors
    ofSetColor(0, 255, 0);
    drawArrow(particle.pos, particle.pos + attractor1.getForce(particle) * 2000);
    ofSetColor(255, 0, 0);
    drawArrow(particle.pos, particle.pos + attractor2.getForce(particle) * 2000);
                
    ofPopStyle();

    gui.draw();
}


void ofApp::keyPressed(int key)
{
    switch (key)
    {
    case'r':
        particle.setup( vec2(ofRandomWidth(), 0) );
        trail.clear();
    default:
        break;
    }
}

