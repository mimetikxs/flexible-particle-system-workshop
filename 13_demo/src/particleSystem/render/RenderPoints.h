#pragma once
#include "Render.h"

using namespace glm;

class RenderPoints : public Render
{
public:

    // rendering parameters
    ofParameter<ofFloatColor> colorBorn;
    ofParameter<ofFloatColor> colorDead;
    ofParameter<float> pointScale;

    void setup(string name) override;
    void update(const ParticleData& pd) override;
    void draw() override;

private:
        
    ofVbo vbo;    
    vector<vec3>  positions;      //< buffers
    vector<float> masses;         //
    vector<float> lifes;          //
    
    int countVisible;

    void allocateVbo(int numVertices);

    // we use a shader to render 
    ofShader shader;
};
