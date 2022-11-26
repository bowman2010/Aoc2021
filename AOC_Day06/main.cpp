#include <iostream>
#include "fishbank.h"
#include "aoc2021.h"

using namespace std;

int main()
{
    auto fb = FishBank(puzzlePath("day6_input.txt"));
//    auto fb = FishBank(puzzlePath("day6_test.txt"));
  //    fb.simulate(18);
  fb.simulate(256);
  return 0;
}
