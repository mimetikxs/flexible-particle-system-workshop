# Emitter

We are going to encapsulate the emitting functionality inside an ``Emitter`` class.

This will give us more control over how we emmit particles:
    - The emit area
    - The properties (``life`` and ``mass``) of the emitted particles
    - The amount of variation in the properties of the emitted particles

We will:

- Explain our new ``Emitter`` class
    - Properties of the emitter (area, position, emitRate)
    - Properties of emitted particles

- Add two emitters to our app

- Introduce the concept of *global parameters* (same for all objects in the system).
