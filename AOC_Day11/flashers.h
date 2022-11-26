#ifndef FLASHERS_H
#define FLASHERS_H
#include <vector>
#include <string>

using namespace std;

/**
 * @brief The OctoDumb class
 * OctoDumb(int nrg) : create an OctoDumb with specified energy
 * void incEnergy()  : increment energy
 * bool tryFlash()   : try to flash (not flashed yet, energy>9)
 *                     if flashed, reset energy to 0 and return true
 * int  getEnergy()  : return energy of the dumbo
 */
class OctoDumb {
    int  energy;
    bool flashed;
public:
    OctoDumb(int nrg);
    void incEnergy();
    bool tryFlash();
    bool hasFlashed();
    void resetFlash();
    int  getEnergy() const;
    void setEnergy(int nrg);
};

/**
 * @class Flasher
 * @brief The Flashers class simulation
 *
 * Flashers(string fname) : create the sim loading spec file
 * void simulate(unsigned nbSteps) : run a simulation of nbSteps steps
 *
 */
class Flashers
{
    vector<vector<OctoDumb>> dumbos;
    unsigned nbRows;
    unsigned nbCols;
public:
    Flashers(string fname);
    void simulate(unsigned nbSteps);
    void findBigFlash();
    bool allFlashed();
    unsigned step();
    void showMap(string msg,int step);
    void sendEnergy(size_t row, std::size_t col);
};

#endif // FLASHERS_H
