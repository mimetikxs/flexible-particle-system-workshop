#pragma once
#include "Render.h"

using namespace glm;

class RenderPoints : public Render
{
public:

    void setup(string name) override;
    void update(const ParticleData& pd) override;
    void draw() override;

private:

    ofVbo vbo;

    // buffer for positions 
    // ofVbo requires that we use vec3 (won't accept vec2)
    vector<vec3> positions;   
    
    // number of vertices to draw
    int countVisible;         
    
    void allocateVbo(int numVertices);
};
