#include "polymer.h"
#include "check.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <climits>
#include <set>

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
    for (unsigned n=10; n<10; n++)
    {
        polymer = chemistry(polymer);
    }
    calcOccurences(polymer);
}

void Polymer::part2()
{
    cout << "Part 2" << endl;
    atomsCount.clear();
    pairsCount.clear();

    // initialize pairs counters from polymer0
    for (unsigned p=0; p<polymer0.length()-1; p++)
        addPair(polymer0.substr(p,2));

    // initialize atoms counters from polymer0
    for (unsigned p=0; p<polymer0.length(); p++)
        addAtom(polymer0.substr(p,1));

    cout << "Polymer0 pairs count = " << pairsCount.size() << endl;
    cout << "Polymer0 atoms count = " << atomsCount.size() << endl;


    for (unsigned i=0; i<40; i++) {
        for (auto &pc: pairsCount) {
            string toInsert = rules.at(pc.first);
            string p1 = pc.first.substr(0,1)+toInsert;
            string p2 = toInsert+pc.first.substr(1,1);
            addPair(p1);
            addPair(p2);
            addAtom(toInsert,pc.second);
//            cout << "p1=" << p1 << " p2=" << p2 << endl;
        }
    }

    for (auto &aa: atomsCount) {
        cout << aa.first << ":" << aa.second << endl;
    }
}

void Polymer::addAtom(string atom, unsigned count)
{
    auto aa = atomsCount.find(atom);
    if (aa==atomsCount.end()) atomsCount.insert(make_pair(atom,1));
        else aa->second+=count;
}

void Polymer::addPair(string pair)
{
    auto aa = pairsCount.find(pair);
    if (aa==pairsCount.end()) pairsCount.insert(make_pair(pair,1));
        else aa->second++;
}

void Polymer::calcOccurences(string polymer)
{
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

