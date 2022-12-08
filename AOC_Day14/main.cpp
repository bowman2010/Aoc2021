#include <iostream>
#include "aoc2021.h"
#include "polymer.h"

using namespace std;

int main()
{
    Polymer polymer(puzzlePath("day14_test1.txt"));
//    Polymer polymer(puzzlePath("day14_input.txt"));


    polymer.doChemistryMagic(5);
//        polymer.doChemistryMagic(40);
    return 0;
}
