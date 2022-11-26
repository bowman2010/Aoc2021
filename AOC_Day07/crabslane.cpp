#include "crabslane.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>

CrabsLane::CrabsLane(std::string puzzlePath)
{
    int crabPos;
    char sep;
    std::string str1,str2;

    std::ifstream fin(puzzlePath);
    getline(fin,str1);

    std::stringstream iss(str1);
    while (iss.good()) {
        iss >> crabPos;
        if (fin.eof()) break;
        crabs.push_back(crabPos);
        iss >> sep;
    }

}

void CrabsLane::part1()
{
    // GetMax position
    size_t n = crabs.size();
    maxPos = 0;
    for (size_t i=0; i<n; i++) {
        if (crabs[i]>maxPos) maxPos=crabs[i];
    }
    std::cout << "Max pos : " << maxPos << std::endl;

    unsigned minFuel = UINT_MAX;
    int bestPos = 0;
    for (int pos=0; pos<=maxPos; pos++) {
        unsigned fuel = calcFuel(pos);
        if (fuel<minFuel) {
            minFuel = fuel;
            bestPos = pos;
        }
    }
    std::cout << "#1 - Best position: " << bestPos << " Fuel: " << minFuel << std::endl;
}

void CrabsLane::part2()
{
    // GetMax position
    size_t n = crabs.size();
    maxPos = 0;
    for (size_t i=0; i<n; i++) {
        if (crabs[i]>maxPos) maxPos=crabs[i];
    }
    std::cout << "Max pos : " << maxPos << std::endl;

    unsigned minFuel = UINT_MAX;
    int bestPos = 0;
    for (int pos=0; pos<=maxPos; pos++) {
        unsigned fuel = calcFuel2(pos);
        if (fuel<minFuel) {
            minFuel = fuel;
            bestPos = pos;
        }
    }
    std::cout << "#1 - Best position: " << bestPos << " Fuel: " << minFuel << std::endl;
}

unsigned CrabsLane::calcFuel(int pos)
{
    size_t n = crabs.size();
    unsigned fuel = 0;

    for (size_t i=0; i<n; i++) {
        fuel += abs(crabs[i]-pos);
    }
    return fuel;
}

unsigned CrabsLane::calcFuel2(int pos)
{
    size_t n = crabs.size();
    unsigned fuel = 0;

    for (size_t i=0; i<n; i++) {
        int moveLen = abs(crabs[i]-pos);
        fuel += (moveLen)*(moveLen+1)/2;
    }
    return fuel;
}
