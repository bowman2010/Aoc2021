#include <iostream>
#include "aoc2021.h"
#include "pathfinder.h"
using namespace std;

#define PART_ONE true
#define PART_TWO true

int main()
{
//    PathFinder pf(puzzlePath("day12_test1.txt"));
//    PathFinder pf(puzzlePath("day12_test2.txt"));
//    PathFinder pf(puzzlePath("day12_test3.txt"));
    PathFinder pf(puzzlePath("day12_input.txt"));

    if (PART_ONE) {
        cout << endl << "Part #1" << endl;
        pf.findPaths();
        cout << "Paths count : " << pf.getPathCount() << endl   ;
    }

    if (PART_TWO) {
        cout << endl << "Part #2" << endl;
        pf.findPaths2();
        cout << "Paths count : " << pf.getPathCount() << endl   ;
    }

    return 0;
}
