#include <array>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "aoc2021.h"
#include "bingosolver.h"
#include <sstream>
using namespace std;

int main()
{
    BingoSolver solver(puzzlePath("day4_input.txt"));
    solver.part1();
    return 0;
}
