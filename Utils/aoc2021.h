#ifndef AOC2021_H
#define AOC2021_H
#include <string>

#define PUZZLE_PATH "/home/bowman/Dev/AOC_Puzzles/"

std::string puzzlePath(std::string fname) {
    std::string ppath = PUZZLE_PATH+fname;
    return ppath;
}
#endif // AOC2021_H
