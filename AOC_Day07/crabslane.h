#ifndef CRABSLANE_H
#define CRABSLANE_H

#include <string>
#include <vector>

class CrabsLane
{
    std::vector<int> crabs;
    int maxPos;
public:
    CrabsLane(std::string puzzlePath);
    void part1();
    void part2();

    unsigned calcFuel(int pos);
    unsigned calcFuel2(int pos);
};

#endif // CRABSLANE_H
