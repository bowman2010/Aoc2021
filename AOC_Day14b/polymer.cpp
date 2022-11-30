#include "polymer.h"
#include "check.h"
#include <sstream>
#include <fstream>

Polymer::Polymer(string fname)
{
    string s1,s2;
    std::fstream inf(fname);
    CHECK(inf);
    inf >> polymer0;

    string rulep1,rulep2;
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
}

void Polymer::initialize()
{
    atomsPairs.clear();
    atoms.clear();
    for (unsigned i=0; i<polymer0.length()-1; i++)
    {
        string pair = polymer0.substr(i,2);
        atoms.add(pair[0]);
        atomsPairs.add(pair);
    }
    atoms.add(polymer0[polymer0.length()-1]);

}


void Polymer::doChemistryMagic(unsigned steps)
{
    initialize();
    for (unsigned i=1; i<steps; i++)
        chemistryReaction();
}

void Polymer::chemistryReaction()
{

}

