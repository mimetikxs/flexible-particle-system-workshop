#pragma once
#include "ofxGui.h"

class Presets
{
public:

    void setup(ofxPanel* gui, int totalPresets);    
    void applyPreset(int i);
    void draw();

private:

    ofxPanel* gui; // pointer to external gui

    ofxPanel guiPresets;
    ofParameter<int> presetIndex;
    ofParameter<void> toggleSave;
    ofParameter<void> toggleLoad;

    void savePreset();
    void loadPreset();
};
