# Motion basics

In this exercise we'll learn the basics about simulating motion:

- Our laws of motion
    - An object at rest stays at rest and an object in motion stays in motion.
    - A force is a vector that causes an object to accelerate.
    - Force = Mass * Accel 

- Position, velocity and acceleration are vectors, they have a direction and a magnitude. They store the current state of a particle.

- Velocity controls how much the position change per frame. Acceleration controls how much the velocity changes per frame.

- To simulate motion, we need to calculate the position of our particle in the future. We move our simulation forward in steps. 

- ```timestep``` controls how big are the steps of the simulation. The base unit is one frame. ``timestep`` is a multiplier that scales the base uinit allowing us to modify the speed at which the simulation progresses. 

- ```friction``` simulates a loss of energy in our system.


### Resources:

[Forces chapter](https://natureofcode.com/book/chapter-2-forces/) from The Nature of Code