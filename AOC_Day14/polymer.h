#ifndef POLYMER_H
#define POLYMER_H

#include <string>
#include <map>

using namespace std;

class Polymer
{
    map<string,string> rules;
    string polymer0;
    bool trace = false;
public:
    Polymer(string fname);
    void part1();
    string chemistry(string base);
};

#endif // POLYMER_H
