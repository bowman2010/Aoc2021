#ifndef BINGO_H
#define BINGO_H
#include <sstream>

#include <ostream>

#define BINGO_SIZE 5

class Bingo
{
private:
    bool completed;
    unsigned score;
    unsigned grid[BINGO_SIZE][BINGO_SIZE];
    bool lights[BINGO_SIZE][BINGO_SIZE];
    unsigned lastCall;
public:
    Bingo();
    friend std::ostream &operator<<( std::ostream &output, const Bingo  &bingo );
    friend std::istream &operator>>( std::istream &input, Bingo &bingo );

    void reset(); // Reset all lights and set score to 0
    bool call(const unsigned nr); // Play a number return true if found
    bool checkCompleted(unsigned line, unsigned column);
    bool isCompleted();
    unsigned calcScore();
};

#endif // BINGO_H
