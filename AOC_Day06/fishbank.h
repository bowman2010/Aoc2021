#ifndef FISHBANK_H
#define FISHBANK_H

#include <string>
#include <vector>

using namespace std;

class FishBank
{
    unsigned long long initial[9];
    unsigned long long fishCountByAge[9];
public:
    FishBank(std::string puzzlePath);
    void part1();
    void part2();
    void simulate(int days);
    void step();
    long long countBank();
};

#endif // FISHBANK_H
