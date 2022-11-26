#include <sstream>
#include "bingo.h"
#include <iomanip>
#include <iostream>

Bingo::Bingo()
{
    reset();
    for (unsigned line=0; line<BINGO_SIZE; line++) {
        for (unsigned column=0; column<BINGO_SIZE; column++) {
            grid[line][column] = 0;
        }
    }
}

void Bingo::reset()
{
    for (unsigned line=0; line<BINGO_SIZE; line++) {
        for (unsigned column=0; column<BINGO_SIZE; column++) {
            lights[line][column] = false;
        }
    }
    completed = false;
    score = 0;
}

bool Bingo::call(const unsigned nr)
{
    bool win = false;
    lastCall = nr;
    for (unsigned line=0; line<BINGO_SIZE; line++) {
        for (unsigned column=0; column<BINGO_SIZE; column++) {
            if (grid[line][column]==nr) {
                lights[line][column]=true;
                win=true;
                checkCompleted(line,column);
            }
        }
    }
    return win;
}

bool Bingo::checkCompleted(unsigned line, unsigned column)
{
    // check vertical
    bool vwin = true;
    for (int l=0; l<BINGO_SIZE; l++) {
        vwin = vwin && lights[l][column];
    }

    // check horizontal
    bool hwin = true;
    for (int c=0; c<BINGO_SIZE; c++) {
        hwin = hwin && lights[line][c];
    }
    completed = hwin||vwin;
    return completed;
}

bool Bingo::isCompleted()
{
    return completed;
}

unsigned Bingo::calcScore()
{
    unsigned sum1 = 0;
    for (int l=0; l<BINGO_SIZE; l++) {
        for (int c=0; c<BINGO_SIZE; c++) {
            if (!lights[l][c]) {
                sum1 += grid[l][c];
            }
        }
    }
    return sum1*lastCall;
}

std::ostream &operator<<( std::ostream &output, const Bingo  &bingo )
{
    for (unsigned line=0; line<BINGO_SIZE; line++) {
        for (unsigned column=0; column<BINGO_SIZE; column++) {
            if (bingo.lights[line][column]) {
                output << " *" << std::setw(2) << bingo.grid[line][column] << "* ";
            } else {
                output << "  " << std::setw(2) << bingo.grid[line][column] << "  ";
            }
        }
        output << std::endl;
    }
    return output;
}

std::istream &operator>>( std::istream &input, Bingo &bingo )
{
    std::string lineStr;
    std::string numStr;

    // Skip emptyLine
    std::getline(input,lineStr);

    for (int lineNr=0; lineNr<BINGO_SIZE; lineNr++) {
        if (input.eof()) {
            std::cerr << "EOF while reading bingo line" << std::endl;
        }
        std::getline(input,lineStr);
        std::istringstream iss(lineStr);
        for (int colNr=0; colNr<BINGO_SIZE; colNr++) {
            iss >> numStr;
            bingo.grid[lineNr][colNr] = stoi(numStr);
        }
    }
    return input;
}

