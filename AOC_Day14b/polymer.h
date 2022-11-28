#ifndef POLYMER_H
#define POLYMER_H

#include <map>
#include <string>


using namespace std;
class Polymer
{
    map<string,string> rules;
    string polymer0;
public:
    Polymer(string fname);
    void doChemistryMagic(unsigned steps);
};

#endif // POLYMER_H
