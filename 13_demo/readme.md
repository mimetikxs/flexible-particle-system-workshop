# Demo 1

In this project we showcase a possible use of the particle system:

- We use one emitter, two forces and two different renderers. 
- The position of emitter and attractor can be controlled by the mouse.
- Two fbos are used to compose the output of our two renderers (each fbo acts as a layer).

Some code has been refactored to make it more modular and easy to follow:
- Encapsulated the logic for saving/loading presets into a ``Presets`` class.
- Moved the debug drawing code into a ``drawDebug`` function
- Added position as a parameter of ``ForceAttractor`` so it will be saved (so far we left it out for simplicity)
