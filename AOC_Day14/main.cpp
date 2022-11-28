#include <iostream>
#include <string>
#include "polymer.h"
#include "aoc2021.h"

using namespace std;

int main()
{
    Polymer polymer(puzzlePath("day14_test1.txt"));
//    Polymer polymer(puzzlePath("day14_input.txt"));

    cout << "Part #1" << endl;
    polymer.doChemistryMagic(10);

    cout << "Part #2" << endl;
    polymer.doChemistryMagic(40);


    return 0;

}
