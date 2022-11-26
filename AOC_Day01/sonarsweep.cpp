#include "sonarsweep.h"

#include <fstream>
#include <iostream>

SonarSweep::SonarSweep(string fname)
{
    string str;
    fstream fin(fname);
    while (getline(fin,str) && !str.empty())
    {
        depthProfile.push_back(stoi(str));
    }
}

void SonarSweep::part1()
{
    cout << "part 1" << endl;
    unsigned incCount = 0;
    unsigned long prevDepth = UINTMAX_MAX;

    for (auto depth: depthProfile) {
        if (depth > prevDepth) {
            incCount++;
        }
        prevDepth = depth;
    }
    cout << "Part 1 : Number of depth increase = " << incCount << endl;
}

void SonarSweep::part2()
{
    unsigned incCount = 0;
    unsigned window[4];
    unsigned rptr = 0;
    unsigned wptr = 0;

    auto depthIter = depthProfile.begin();
    for (int i=0; i<3; i++) {
        window[wptr] = *depthIter;
        wptr++; depthIter++;
    }

    while (depthIter<depthProfile.end()) {
        window[wptr] = *depthIter;
        unsigned a = window[rptr]+window[(rptr+1)%4]+window[(rptr+2)%4];
        unsigned b = window[(rptr+1)%4]+window[(rptr+2)%4]+window[(rptr+3)%4];
        if (b>a) incCount++;
        rptr = (rptr+1)%4;
        wptr = (wptr+1)%4;
        depthIter++;
    }

    cout << "Part 2 : Increment count = " << incCount << endl;
}

