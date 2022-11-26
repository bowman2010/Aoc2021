#include <iostream>
#include "aoc2021.h"
#include "heightmap.h"

using namespace std;

int main()
{
//    HeightMap hmap(puzzlePath("day9_test.txt"));
    HeightMap hmap(puzzlePath("day9_input.txt"));
    hmap.findLowPoints();
    hmap.calcRisk();
    hmap.findBassins();
    return 0;
}
