#include "seg7.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

Seg7::Seg7(std::string puzzlePath)
{
    std::string line;

    std::ifstream fin(puzzlePath);
    while (getline(fin, line) && !line.empty()) {
        notes.push_back(NoteLine(line));
    }
    cout << "Loaded " << notes.size() << " notes lines" << endl;
}

void Seg7::part1()
{
    // specific #segments for numbers
    // 1 -> 2 segs
    // 4 -> 4 segs
    // 7 -> 3 segs
    // 8 -> 7 segs
    unsigned count = 0;
    for (auto &note: notes) {
        count += note.count2347();
    }
    cout << "count of 1 4 7 or 8 : " << count << endl;
}

NoteLine::NoteLine(const std::string line)
{
    stringstream iss(line);
    string inputsStr;
    string outputsStr;
    string str1;
    getline(iss, inputsStr, '|');
    getline(iss,outputsStr);

    iss = stringstream(inputsStr);
    for (int i=0; i<10; i++) {
        iss >> str1;
        inputs.push_back(str1);
    }

    iss = stringstream(outputsStr);
    for (int i=0; i<4; i++) {
        iss >> str1;
        outputs.push_back(str1);
    }
}

unsigned NoteLine::count2347()
{
    unsigned count = 0;
    for (auto &op : outputs) {
        unsigned l =  (op.length());
        if (l==2 || l==3 || l==4 || l==7) count++;
    }
    return count;
}

