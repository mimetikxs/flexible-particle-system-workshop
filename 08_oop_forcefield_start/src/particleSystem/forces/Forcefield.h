#pragma once
#include "ofMain.h"
#include "Force.h"

using namespace glm;

class Forcefield : public Force
{
public:

    ofParameter<float> forceScale;
    ofParameter<float> noiseScale;
    ofParameter<float> noiseSpeed;
    
    // inherited functionality
    void setup(string name) override;
    void applyForce(Particle& p) override;
    void draw() override;

    // specific functionality
    void setupGrid(float width, float height, float cellSize);
    void updateNoise();

protected:

    int cols = 0;
    int rows = 0;
    float cellSize = 0;

    // our grid is stored in a 1 dimensional array
    vector<vec2> forces;

    vec2 getForceAtCell(int col, int row);
};