#include "polymer.h"
#include "check.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <climits>

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
}


void Polymer::part1()
{
    string polymer = polymer0;
    cout << "polymer0 = " << polymer << endl;
    for (unsigned n=0; n<10; n++)
    {
        polymer = chemistry(polymer);
    }

    map<char,unsigned> occurences;
    for (unsigned p=0; p<polymer.length(); p++) {
        if (occurences.find(polymer[p])!=occurences.end())
            occurences.at(polymer[p])++;
        else occurences.insert(make_pair(polymer[p],1));
    }
    unsigned atomMinCount=UINT_MAX;
    unsigned atomMaxCount=0;
    char atomMin = '?';
    char atomMax = '?';
    for (auto &aa: occurences)
    {
        if (aa.second>atomMaxCount) { atomMax=aa.first; atomMaxCount=aa.second; }
        if (aa.second<atomMinCount) { atomMin=aa.first; atomMinCount=aa.second; }
    }
    cout << "Atom max : " << atomMax << " : " << atomMaxCount << endl;
    cout << "Atom min : " << atomMin << " : " << atomMinCount << endl;
    cout << "Response : " << atomMaxCount-atomMinCount << endl;
}

string Polymer::chemistry(string base)
{
    string polymer0(base);
    string polymer1;

    if (trace) {
        cout << "chemistry" << endl;
        cout << "  base : " << polymer0 << endl;
    }
    for (unsigned p=0; p<polymer0.length()-1; p++)
    {
        string atomPair = polymer0.substr(p,2);
        string toInsert = rules.at(atomPair);
        if (trace) {
            cout << "   rule " << atomPair << " -> ";
            cout << toInsert;
        }
        polymer1.append(polymer0.substr(p,1));
        polymer1.append(toInsert);
        if (trace) { cout << " gives " << polymer1 << endl; }
    }
    polymer1.append(base.substr(base.length()-1,1));
    if (trace) { cout << "  result : " << polymer1 << endl; }
    return polymer1;
}

