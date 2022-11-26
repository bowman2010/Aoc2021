#ifndef FISHBANK_H
#define FISHBANK_H


#include <string>
#include <vector>
class FishBank
{
    long long initial[9];
    long long fishCountByAge[9];
public:
    FishBank(std::string puzzlePath);
    void simulate(int days);
    void step();
    long long countBank();
};

#endif // FISHBANK_H
