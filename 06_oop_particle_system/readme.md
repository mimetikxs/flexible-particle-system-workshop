# OOP: Particle system

We have refactored our code to encapsulate the simulation functionality inside a ``ParticleSystem`` class. This removes all the simulation logic from ``ofApp`` and makes our code more manageable.

We have implemented an interface to be able to add any number of external forces and attractors

- ``ParticleSystem::AddForce()``
- ``ParticleSystem::AddEmitter()``

If we want to store objects from outside the ``ParticleSystem`` class, we need to use **vectors of pointers**. 
The object "lives" in our ofApp but we can reference that object insideo our ``ParticleSystem`` class. If we didn't use pointers, we will have a copy (a different object).

We will:

- Explain ``ParticleSystem`` class. Most of the logic is the same we had in ofApp in the previous project.
- Show how to use our brand new ``ParticleSystem`` in ``ofApp`` (one emitter and one attractor to keep things simple).

### Folder structure changes:
- We've rearanged our folder structure, grouping our classes in a more meaningful way. This will be useful as the number of classes grows.


### Resources
https://openframeworks.cc/ofBook/chapters/memory.html#pointersandreferences