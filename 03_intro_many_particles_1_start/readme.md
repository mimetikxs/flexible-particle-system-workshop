# Many particles (part 1): Dynamically add/remove particles

We are ready to expand our system to simulate many particles. We'll use an array ``vector<Particles>`` to store our particles in memory. 

We also want to be able to add and remove particles. Two approaches:
1. Dynamically add/remove particles to memory
2. Use a *particle pool*

In this exercise we'll implement the first approach.

We'll learn:

- Emmit particles: Add particles with ``vector::push_back()``

- Add a lifespan to particles

- When a particle dies, we remove it with ``vector::erase()``

- Add parameters to control the lifespan and emit rate of particles.
    - Experiment with different values to see how ``maxNumParticles``, ``emitRate`` and ``life`` are related.

