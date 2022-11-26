#include <iostream>
#include "bdiagnostic.h"
#include "aoc2021.h"
using namespace std;

int main()
{
    BDiagnostic diag(puzzlePath("day3_input.txt"));
//    BDiagnostic diag(puzzlePath("day3_test.txt"));
    diag.part1();
    diag.part2();
    return 0;
}
