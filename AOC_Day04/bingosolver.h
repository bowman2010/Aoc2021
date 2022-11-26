#ifndef BINGOSOLVER_H
#define BINGOSOLVER_H
#include <sstream>
#include "bingo.h"
#include <vector>

class BingoSolver
{
    std::vector<unsigned> numbers;
    std::vector<Bingo> bingos;
public:
    BingoSolver(const std::string &puzzleFile);
    void part1();
private:
    bool loadPuzzle(const std::string &puzzleFile);
};

#endif // BINGOSOLVER_H
