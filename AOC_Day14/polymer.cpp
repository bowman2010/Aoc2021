#include "polymer.h"
#include "check.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>

Polymer::Polymer(string fname)
{
    string s1,s2;
    std::fstream inf(fname);
    CHECK(inf);
    inf >> polymer0;

    string rulep1;
    string rulep2;
    while (getline(inf,s1))
    {
        if (!s1.empty()) {
            stringstream ss1(s1);
            ss1 >> rulep1;
            ss1 >> s2;
            ss1 >> rulep2;
            rules.insert(make_pair(rulep1,rulep2));
        }
    }
    cout << "Puzzle Loaded" << endl;
    cout << "Polymer zero : " << polymer0 << endl;
    cout << "Rules:" << endl;
    for (auto &rule : rules){
        cout << "  " << rule.first << " => " << rule.second << endl;
    }    
    initialize();
}

void Polymer::initialize()
{
    atomsPairs.clear();
    atoms.clear();
    for (unsigned i=0; i<polymer0.length()-1; i++)
    {
        string pair = polymer0.substr(i,2);
        atoms.add(pair.substr(0,1));
        atomsPairs.add(pair);
    }
    atoms.add(polymer0.substr(polymer0.length()-1,1));
}

string Polymer::getRule(string pair)
{
    auto itr = rules.find(pair);
    if (itr==rules.end()) {
        cout << endl << "Error : cannot find rule for " << pair << endl;
        exit(1);
    }
    return itr->second;
}


void Polymer::doChemistryMagic(unsigned steps)
{
    initialize();
    showStats();

    for (unsigned i=1; i<=steps; i++) {
        cout << endl << "Step " << i << endl;
        chemistryReaction();
        showStats();
    }
}

void Polymer::showStats()
{
    cout << "Atoms: ";
    for (auto &apc : atoms.getCounters())
    {
        cout << "  " << apc.first << "(" << apc.second << "), ";
    }
    cout << endl;
    cout << "pairs: " << atomsPairs.sum() << endl;
    cout << "atoms: " << atoms.sum() << endl;
    cout << "min : " << atoms.min() << endl;
    cout << "max : " << atoms.max() << endl;
    cout << endl;
}

void Polymer::chemistryReaction()
{
    cout << "reaction" << endl;
    for (auto &apc : atomsPairs.getCounters())
    {
        string pair     = apc.first;
        unsigned count  = apc.second;
        string atom     = getRule(pair);

        string newPair1 = pair.substr(0,1)+atom;
        string newPair2 = atom+pair.substr(1,1);

        cout << setw(8) << count << " * "  << pair << " => " << newPair1 << " " << newPair2 << endl;

        atomsPairs.removeAll(apc.first,true);
        atoms.add(atom,count);
        atomsPairs.add(newPair1,count);
        atomsPairs.add(newPair2,count);
    }
}

