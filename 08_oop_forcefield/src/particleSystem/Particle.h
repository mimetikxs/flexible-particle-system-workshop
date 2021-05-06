#pragma once
#include "ofMain.h"

using namespace glm;

class Particle
{
public:
	
	vec2 pos;
	vec2 vel;
	vec2 accel;
	float mass = 1;

	float elapsedLife = 0;
	float maxLife = 0;

	void setup(vec2 position, float maxLife, float mass = 1);
	void applyForce(vec2 force);
	void update(float friction = 0, float timestep = 1);

};