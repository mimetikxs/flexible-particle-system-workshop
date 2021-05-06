#pragma once
#include "ofMain.h"
#include "ParticleData.h"

using namespace glm;

class Emitter
{
public:
	
	ofParameterGroup parameters;
	ofParameter<float> emitRate;
	ofParameter<float> x;
	ofParameter<float> y;
	ofParameter<float> width;
	ofParameter<float> height;
	
	// particles will be emitted with these properties
	float life = 1;
	float lifeVariation = 1; // 1 = no variation
	float mass = 1;
	float massVariation = 1; // 1 = no variation

	void setup(string name);
	void emit(ParticleData& pd);
	void draw();
};
