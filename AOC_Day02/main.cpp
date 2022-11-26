#include <iostream>
#include "dive.h"
#include "aoc2021.h"
using namespace std;

int main()
{
    Dive dive(puzzlePath("day2_input.txt"));
    dive.part1();
    dive.part2();
    return 0;
}
