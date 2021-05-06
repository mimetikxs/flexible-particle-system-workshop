#pragma once
#include "ofMain.h"
#include "Emitter.h"

class EmitterRect : public Emitter
{
public:
	
	ofParameter<float> x;
	ofParameter<float> y;
	ofParameter<float> width;
	ofParameter<float> height;
	
	void setup(string name) override;
	void emit(ParticleData& pd) override;
	void draw() override;
};
