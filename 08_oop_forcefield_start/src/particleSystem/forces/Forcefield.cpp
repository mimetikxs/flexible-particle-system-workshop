#include "Forcefield.h"


void Forcefield::setup(string name)
{
    parameters.setName(name);
    parameters.add( noiseScale.set( "noise scale", 0.009, 0.001, 0.15));
    parameters.add( noiseSpeed.set( "noise speed", 0, 0, 0.5));
    parameters.add( forceScale.set( "force scale", 1, 0.001, 10));
}


void Forcefield::setupGrid(float width, float height, float _cellSize)
{
    cellSize = _cellSize;

    cols = ceil(width / cellSize);
    rows = ceil(height / cellSize);

    // init the grid of vectors (all will be 0)
    forces.resize(cols * rows); 
}


void Forcefield::updateNoise()
{
    float offset = ofGetElapsedTimef() * noiseSpeed;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            // get noise value between 0..1
            //float noise = ofRandom(0, 1);
            float noise = ofNoise(
                x * noiseScale + offset,
                y * noiseScale + offset
            );
            // remap noise value to an angle in radians
            noise = ofMap(noise, 0.0, 1.0, 0.0, TWO_PI);

            // find the index 
            int i = (x + y * cols);

            // angle to unit vector
            forces[i].x = cos(noise);
            forces[i].y = sin(noise);
        }
    }
}


void Forcefield::applyForce(Particle& p)
{
    // find column and row
    int col = ceil(p.pos.x / cellSize) - 1;
    int row = ceil(p.pos.y / cellSize) - 1;

    // only apply force to particles inside the grid
    if (col >= 0 && col < cols && row >= 0 && row < rows)
    {
        p.applyForce( getForceAtCell(col, row) * forceScale.get() );
    }
}


vec2 Forcefield::getForceAtCell(int col, int row)
{
    // maps a 2d coordinate to a 1d coordinate
    int i = col + row * cols;
    return forces[i];
}


void Forcefield::draw()
{
    ofPushStyle();
    ofNoFill();

    float halfCellSize = cellSize * 0.5;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            vec2 cellCenter = vec2(x, y) * cellSize + halfCellSize;
            
            // draw cells
            //ofDrawRectangle(cellCenter - vec2(halfCellSize), cellSize, cellSize);
            
            // draw force vectors
            vec2 vec = getForceAtCell(x, y) * 20;
            ofDrawLine(cellCenter, cellCenter + vec);
        }
    }

    ofPopStyle();
}
