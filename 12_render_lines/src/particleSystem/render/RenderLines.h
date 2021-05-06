#pragma once
#include "Render.h"

using namespace glm;

class RenderLines : public Render
{
public:

    ofParameter<ofFloatColor> colorBorn;
    ofParameter<ofFloatColor> colorDead;

    void setup(string name) override;
    void update(const ParticleData& pd) override;
    void draw() override;

private:
       
    ofVbo vbo; 
    vector<vec3>  positions;     //< buffers
    vector<float> lifes;         //
    
    int countVisible;

    void allocateVbo(int numVertices);

    // we use a shader to render 
    ofShader shader;
};
