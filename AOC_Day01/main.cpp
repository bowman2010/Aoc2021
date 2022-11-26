#include <iostream>
#include "sonarsweep.h"
#include "aoc2021.h"
using namespace std;

int main()
{
    SonarSweep ssweep(puzzlePath("day1_input.txt"));
    ssweep.part1();
    ssweep.part2();
    return 0;
}
