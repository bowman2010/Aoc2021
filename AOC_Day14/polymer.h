#ifndef POLYMER_H
#define POLYMER_H

#include <string>
#include <map>

using namespace std;

class Polymer
{
    map<string,string> rules;
    string polymer0;

    map<string,unsigned> pairsCount;
    map<string,unsigned> atomsCount;
    bool trace = false;
public:
    Polymer(string fname);
    void part1();
    void part2();
    void addAtom(string atom, unsigned count=1);
    void addPair(string pair);
    void calcOccurences(string polymer);
    string chemistry(string base);
};

#endif // POLYMER_H
