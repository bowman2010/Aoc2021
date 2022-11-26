#include "flashers.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


OctoDumb::OctoDumb(int nrg)
{
    flashed = false;
    energy = nrg;
}

void OctoDumb::incEnergy() {
    energy++;
}

bool OctoDumb::tryFlash()
{
    if (!flashed && energy>9) {
        flashed = true;
        return true;
    }
    return false;
}

bool OctoDumb::hasFlashed()
{
    return flashed;
}

void OctoDumb::resetFlash()
{
    flashed = false;
}

int OctoDumb::getEnergy() const
{
    return energy;
}

void OctoDumb::setEnergy(int nrg)
{
    energy = nrg;
}


Flashers::Flashers(string fname)
{
    std::fstream inf(fname);
    std::string fLine;
    while (getline(inf,fLine) && !fLine.empty())
    {
        vector<OctoDumb> v1;
        for (unsigned i=0; i<fLine.length(); i++) {
            v1.push_back(OctoDumb(fLine[i]-'0'));
        }
        dumbos.push_back(v1);
    }
    nbRows = dumbos.size();
    nbCols = dumbos[0].size();
}

void Flashers::simulate(unsigned nbSteps)
{
    unsigned flashCounter = 0;

    for (unsigned i=1; i<=nbSteps; i++) {
        unsigned fcount = step();
        flashCounter += fcount;
    }
    cout << "Flash count after " << nbSteps << " steps : " << flashCounter << endl;
}

void Flashers::findBigFlash()
{
    bool bigFlash = false;
    unsigned i = 0;

    while(!bigFlash) {
        i++;
        step();
        if (allFlashed()) {
            cout << "***** 1st big flash at step " << i << endl;
            showMap("BigFlash ",i);
            return;
        }
    }
    cout << "No big flash found !!" << endl;
}

bool Flashers::allFlashed()
{
    for (unsigned row=0; row<dumbos.size(); row++)
    for (unsigned col=0; col<dumbos[row].size(); col++)
        if (!dumbos[row][col].hasFlashed()) return false;
    return true;
}

unsigned Flashers::step()
{
    unsigned stepFlashesCount = 0;

    // Reset flashes and increase energy by 1
    for (unsigned row=0; row<dumbos.size(); row++)
    for (unsigned col=0; col<dumbos[row].size(); col++)
    {
        dumbos[row][col].resetFlash();
        dumbos[row][col].incEnergy();
    }

    unsigned flashCount;
    do {
        flashCount = 0;

        for (unsigned row=0; row<nbRows; row++)
        for (unsigned col=0; col<nbCols; col++)
        {
            OctoDumb &dmb = dumbos[row][col];
            if (dmb.tryFlash()) {
                flashCount++;
                sendEnergy(row,col);
            }
        }
        stepFlashesCount += flashCount;

        stringstream so1("");
        so1 << "";
    } while (flashCount>0);

    for (unsigned row=0; row<dumbos.size(); row++)
    for (unsigned col=0; col<dumbos[row].size(); col++)
        if (dumbos[row][col].hasFlashed()) dumbos[row][col].setEnergy(0);

    return stepFlashesCount;
}

void Flashers::sendEnergy(size_t row, size_t col)
{
        // On same row
        if (col>0)              dumbos[row][col-1].incEnergy();
        if (col<nbCols-1)       dumbos[row][col+1].incEnergy();

        // On row above
        if (row>0) {
            dumbos[row-1][col].incEnergy();
            if (col>0)          dumbos[row-1][col-1].incEnergy();
            if (col<nbCols-1)   dumbos[row-1][col+1].incEnergy();
        }

        // On row below
        if (row<nbRows-1) {
            dumbos[row+1][col].incEnergy();
            if (col>0)          dumbos[row+1][col-1].incEnergy();
            if (col<nbCols-1)   dumbos[row+1][col+1].incEnergy();
        }
}

void Flashers::showMap(string msg, int step)
{
    cout << "-----------------------------" << endl;
    cout << msg << " step " << step << endl;

    for (unsigned row=0; row<nbRows; row++) {
        for (unsigned col=0; col<nbCols; col++)
        {
            cout << dumbos[row][col].getEnergy();
        }
        cout << endl;
    }
}

