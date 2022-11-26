#ifndef DIVE_H
#define DIVE_H

#include <string>
#include <vector>

using namespace std;

struct Command {
    string action;
    int value;
    Command(string s);

public:
    void setArg(int newArg);
};

class Dive
{
    vector<Command> commands;
public:
    Dive(string fname);
    void part1();
    void part2();
};

#endif // DIVE_H
