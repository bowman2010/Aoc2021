#include "bingosolver.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

BingoSolver::BingoSolver(const std::string &puzzleFile)
{
    loadPuzzle(puzzleFile);
}

void BingoSolver::part1()
{
    Bingo first;
    Bingo last;
    bool haveFirst = false;

    for(unsigned number: numbers) {
        auto ptr = bingos.begin();
        while (ptr<bingos.end()) {
            if (!ptr->isCompleted()) {
                ptr->call(number);
                if (ptr->isCompleted()) {
                    if (!haveFirst) { first = *ptr; haveFirst=true; }
                    last = *ptr;
                }
            }
            ptr++;
        }
    }
    std::cout << "First completed bingo " << std::endl << first << std::endl;
    std::cout << "Score = " << first.calcScore() << std::endl;
    std::cout << "Last completed bingo " << std::endl << last << std::endl;
    std::cout << "Score = " << last.calcScore() << std::endl;
}

bool BingoSolver::loadPuzzle(const std::string &puzzleFile)
{
    std::string numbersStr;
    std::string lineStr;
    std::string nstr;

    std::ifstream pf(puzzleFile, std::ios_base::in);
    if (pf.bad()) {
        throw "Cannot load puzzle file";
    }

    // Load numbers
    std::getline(pf,numbersStr);
    std::stringstream iss(numbersStr);
    numbers.clear();
    while (!iss.eof()) {
        getline(iss,nstr,',');
        numbers.push_back(std::stoi(nstr));
    }

    // Load bingos
    bingos.clear();
    for (int i=0; i<100; i++) {
        Bingo bingo;
        pf >> bingo;
        bingos.push_back(bingo);
    }
    std::cout << "Loaded " << bingos.size() << " Bingos" << std::endl;


    return true;
}



