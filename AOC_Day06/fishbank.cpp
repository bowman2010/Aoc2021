#include "fishbank.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>



FishBank::FishBank(std::string puzzlePath)
{
    int fishAge;
    char sep;
    std::string str1,str2;

    std::ifstream fin(puzzlePath);
    getline(fin,str1);

    for (int i=0; i<=8; i++) initial[i]=0;

    std::stringstream iss(str1);
    while (iss.good()) {
        iss >> fishAge;
        if (fin.eof()) break;
        initial[fishAge]++;
        iss >> sep;
    }
}


void FishBank::simulate(int days)
{
    for (int i=0; i<=8; i++) fishCountByAge[i]=initial[i];

    for (int i=1; i<=days; i++) {
        step();
        std::cout << "#Fishes after " << std::setw(4) << i << " days: " ;
        countBank();
    }
    std::cout << std::endl;
}

void FishBank::step()
{
    unsigned reproducers = fishCountByAge[0];
    for (unsigned i=0; i<8; i++) {
        fishCountByAge[i] = fishCountByAge[i+1];
    }
    fishCountByAge[8]=reproducers;
    fishCountByAge[6]+=reproducers;
}

long long FishBank::countBank()
{
    long long total = 0;
    for (unsigned i=0; i<=8; i++) {
        total += fishCountByAge[i];
        std::cout << i << ":" << fishCountByAge[i] << " ";
    }
    std::cout << "total:" << total << std::endl;

    return total;
}

