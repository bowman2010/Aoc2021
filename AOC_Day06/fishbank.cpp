#include "fishbank.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>



FishBank::FishBank(string puzzlePath)
{
    int fishAge;
    char sep;
    string str1,str2;

    ifstream fin(puzzlePath);
    getline(fin,str1);

    for (int i=0; i<=8; i++) initial[i]=0;

    stringstream iss(str1);
    while (iss.good()) {
        iss >> fishAge;
        if (fin.eof()) break;
        initial[fishAge]++;
        iss >> sep;
    }
}

void FishBank::part1()
{
    cout << "Part #1" << endl;
    simulate(80);
    countBank();
    cout << endl;
}

void FishBank::part2()
{
    cout << "Part #2" << endl;
    simulate(256);
    countBank();
    cout << endl;
}


void FishBank::simulate(int days)
{
    for (int i=0; i<=8; i++) fishCountByAge[i]=initial[i];
    for (int i=1; i<=days; i++)  step();
    cout << endl;
}

void FishBank::step()
{
    unsigned long long reproducers = fishCountByAge[0];
    for (unsigned i=0; i<8; i++) {
        fishCountByAge[i] = fishCountByAge[i+1];
    }
    fishCountByAge[8]  = reproducers;
    fishCountByAge[6] += reproducers;
}

long long FishBank::countBank()
{
    long long total = 0;
    for (unsigned i=0; i<=8; i++) {
        total += fishCountByAge[i];
        cout << i << ":" << fishCountByAge[i] << " ";
    }
    cout << endl << "total:" << total << endl << endl;

    return total;
}

