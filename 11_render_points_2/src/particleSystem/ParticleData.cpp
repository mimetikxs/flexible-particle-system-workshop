#include "ParticleData.h"


void ParticleData::generate(int numParticles)
{
    particles.resize(numParticles);
    count = numParticles;
    countAlive = 0;
}


void ParticleData::kill(int i) {
    swap(particles[i], particles[countAlive - 1]);
    countAlive--;
}


void ParticleData::wake(int i) {
    swap(particles[i], particles[countAlive]);
    countAlive++;
}