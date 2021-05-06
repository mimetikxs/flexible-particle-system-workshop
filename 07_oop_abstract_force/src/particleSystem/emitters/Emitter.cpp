#include "Emitter.h"


void Emitter::setup(string name)
{
    parameters.setName(name);
    parameters.add( emitRate.set("emit rate", 0, 0, 500));
    parameters.add( x.set("x", 0, 0, ofGetWidth()));
    parameters.add( y.set("y", 0, 0, ofGetHeight()));
    parameters.add( width.set("width", 0, 0, ofGetWidth()));
    parameters.add( height.set("height", 0, 0, ofGetHeight()));
}


void Emitter::emit(ParticleData& pd)
{
    // range of dead particles
    int fist = pd.countAlive;
    int last = MIN(fist + emitRate, pd.count);

    for (int i = fist; i < last; i++)
    {
        vec2 newPos;
        newPos.x = ofRandom(x, x + width);
        newPos.y = ofRandom(y, y + height);

        float newLife = life * ofRandom(1, lifeVariation);

        float newMass = mass * ofRandom(1, massVariation);

        pd.particles[i].setup(newPos, newLife, newMass);
        pd.wake(i);
    }
}

void Emitter::draw()
{
    ofPushStyle();
    ofNoFill();
    ofDrawRectangle(x, y, width, height);
    ofPopStyle();
}
