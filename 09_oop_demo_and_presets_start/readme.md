# OOP: ParticleSystem explorations and presets

Our particle system logic is now complete.

- We have coded a modular system that can be reused in many projects.
- It is also extendable. We can add new types of forces and emitters by extending our abstract classes.
- Depending on our needs, any number and types of emitters and forces can be added to the simulation.
- Parameters are easy to control, we only need to add the ``parameters`` group of our objects to expose them to a GUI. We can have more fine-grained control of the parameters addings individual ones instead of the group.

In this project we'll showcase these features.

We will also learn how to create presets to save and load combinations of parameters. This will be a powerfull tool to explore the possibilities of our system.


### What has changed from the previous project:
- The old ``Emitter`` class has been renamed to ``EmitterRect`` and inherits from a new abstract ``Emitter`` class.
- The gui begins collapsed


### What we are going to do: 
- Create the objects for our simulation (no need to set default parameters, we'll rely on presets): 
    - ``ParticleSystem``
    - ``EmitterRect``
    - ``ForceWind``, ``ForceAttraction``, ``Forcefield``
- Basic save/load of parameters using the gui buttons
- Advanced save/load using ``ofPanel::saveToFile`` and ``ofPanel::loadFromFile()``
- 


### Ideas to explore further:
- Add another type of emitter (eg: ``EmitterCircle``, ``EmitterRing``) that extends our virtual class ``Emitter``