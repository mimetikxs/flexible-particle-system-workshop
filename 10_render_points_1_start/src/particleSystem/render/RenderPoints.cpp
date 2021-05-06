#include "RenderPoints.h"


void RenderPoints::setup(string name)
{
    parameters.setName(name);
}


void RenderPoints::update(const ParticleData& pd)
{
    // lazy initialization pattern:
    // allocate only when is needed (eg: when number of particles changes)
    if (vbo.getNumVertices() != pd.count)
    {
        allocateVbo(pd.count);
    }

    // --------------------------------------
    // copy particle data into vertex buffers
    // --------------------------------------
    
    // only update particles that are alive
    for (int i = 0; i < pd.countAlive; i++)
    {
        // copy the particle position to the vertex buffer
        positions[i].x = pd.particles[i].pos.x;
        positions[i].y = pd.particles[i].pos.y;
    }

    // store visible count to use on draw()
    countVisible = pd.countAlive;
}


void RenderPoints::draw()
{     
    // send the buffer to the gpu    
    vbo.updateVertexData(&positions[0], countVisible);

    // draw the vbo as points 
    vbo.draw(GL_POINTS, 0, countVisible);
}


void RenderPoints::allocateVbo(int numVertices)
{
    // resize positions buffer to fit the max number of particles
    positions.resize(numVertices, vec3(0.0));

    // register the buffer with the vbo
    // GL_DYNAMIC_DRAW means we'll update positions every frame
    vbo.setVertexData(&positions[0], numVertices, GL_DYNAMIC_DRAW);
}