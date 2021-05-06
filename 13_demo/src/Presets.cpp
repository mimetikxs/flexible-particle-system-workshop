#include "Presets.h"

void Presets::setup(ofxPanel* _gui, int totalPresets)
{
    // store pointer
    gui = _gui;
         
    guiPresets.setup("presets");
    guiPresets.add(presetIndex.set("index", 0, 0, totalPresets));
    guiPresets.add(toggleLoad.set("<-- LOAD"));
    guiPresets.add(toggleSave.set("<-- SAVE"));
    guiPresets.setPosition(ofGetWidth() - 220, 20);

    toggleLoad.addListener(this, &Presets::loadPreset);
    toggleSave.addListener(this, &Presets::savePreset);
}


void Presets::savePreset()
{
    gui->saveToFile("preset-" + ofToString(presetIndex) + ".xml");
}


void Presets::loadPreset()
{
    gui->loadFromFile("preset-" + ofToString(presetIndex) + ".xml");
}


void Presets::draw()
{
    guiPresets.draw();
}


void Presets::applyPreset(int i)
{
    presetIndex = i;
    loadPreset();
}