#ifndef POLYMER_H
#define POLYMER_H

#include <string>
#include <map>

using namespace std;

class Polymer
{
    map<string,string> rules;
    string start;
public:
    Polymer(string fname);
};

#endif // POLYMER_H
