#include <iostream>
#include "aoc2021.h"
#include "polymer.h"

using namespace std;

int main()
{
    Polymer polymer(puzzlePath("day14_test1.txt"));
//    Polymer polymer(puzzlePath("day14_input.txt"));
    polymer.part1();
    polymer.part2();
    return 0;}
