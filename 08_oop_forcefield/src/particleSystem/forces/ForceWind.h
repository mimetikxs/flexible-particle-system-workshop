//
// A constant force
//

#pragma once
#include "Force.h"

using namespace glm;

class ForceWind : public Force
{
public:

    ofParameter<vec2> force;

    void setup(string name) override;

    void applyForce(Particle& p) override;

    void draw() override;
};
