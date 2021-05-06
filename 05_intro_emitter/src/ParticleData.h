//
// This class manages creation and destruction of particles.
// All alive particles are stored continously in memory, 
// this helps to speed up updating and rendering the simulation.
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class ParticleData
{
public:

    // alive particles are stored at the front of the vector
    vector<Particle> particles;
    int count;
    int countAlive;

    void generate(int numParticles);
    void wake(int i);
    void kill(int i);
};

