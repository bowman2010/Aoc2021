#include <iostream>
#include "ventssolver.h"
#include "aoc2021.h"

using namespace std;

int main()
{

    VentsSolver vs(puzzlePath("day5_input.txt"));
//    VentsSolver vs(puzzlePath("day5_test.txt"));
    vs.part1();
    return 0;
}
