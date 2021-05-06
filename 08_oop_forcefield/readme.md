# OOP: Forcefields

So far our forces have been constant (wind) or based on distance (attraction).

Here we introduce forcefields:

- They are essentially a grid of vec2 that we'll use as forces.
- To apply a force, we find which cell of the grid our particle is in, and apply its value.

We'll use perlin noise to set the values of the cells, but we could use any algorithm to populate the cells of the grid.

### What we are going to do:
- Explain the new ``ForceField`` class (a child of ``Force``)
- Use ``ForceField`` in our app

### Ideas to explore:
- Explore other ways of populating the cells of the grid
- Interpolate the values of neighbouring cells (this will get smoother trajectories but is more expensive to compute)

### Resources:
https://natureofcode.com/book/chapter-6-autonomous-agents/#66-flow-fields
