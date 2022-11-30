#include <iostream>
#include "aoc2021.h"
#include "polymer.h"

using namespace std;

int main()
{
    Polymer poly(puzzlePath("day14_test1.txt"));
//    Polymer polymer(puzzlePath("day14_input.txt"));
    poly.doChemistryMagic(10);
    poly.doChemistryMagic(40);
    return 0;
}
