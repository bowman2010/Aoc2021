#include <iostream>
#include "aoc2021.h"
#include "aocdebugger.h"

using namespace std;

int main()
{
//    AocDebugger debugger(puzzlePath("day10_test.txt"));
    AocDebugger debugger(puzzlePath("day10_input.txt"));
    debugger.checkPairs();
    debugger.completeLines();
    return 0;
}
