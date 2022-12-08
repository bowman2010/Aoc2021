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
    bml::ItemCounter<string> atoms;

public:
    Polymer(string fname);

    void doChemistryMagic(unsigned steps);
    void showStats();
private:
    void chemistryReaction();
    void initialize();
    string getRule(string pair);
};

#endif // POLYMER_H
