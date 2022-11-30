#ifndef POLYMER_H
#define POLYMER_H

#include <map>
#include <string>
#include <itemCounter.h>

using namespace std;
class Polymer
{
    map<string,string> rules;
    string polymer0;
    bml::ItemCounter<string> atomsPairs;
    bml::ItemCounter<char> atoms;

public:
    Polymer(string fname);

    void doChemistryMagic(unsigned steps);
    void chemistryReaction();
    void initialize();
};

#endif // POLYMER_H
