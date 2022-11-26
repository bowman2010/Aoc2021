#include <iostream>
#include "aoc2021.h"
#include "flashers.h"

using namespace std;

int main()
{
//    Flashers flashers(puzzlePath("day11_test.txt"));
//    Flashers flashers(puzzlePath("day11_test2.txt"));
    Flashers flashers(puzzlePath("day11_input.txt"));
    flashers.simulate(100);
    flashers.findBigFlash();
    return 0;
}
