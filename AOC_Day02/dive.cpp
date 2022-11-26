#include "dive.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Command::Command(string s)
{
    stringstream ss1(s);
    ss1 >> action;
    ss1 >> value;
}

Dive::Dive(string fname)
{
    std::ifstream inf(fname);
    std::string line;
    commands.clear();

    while (getline(inf,line) && !line.empty())
        commands.push_back(Command(line));
}

void Dive::part1()
{
    int position = 0;
    int depth = 0;
    for (auto &cmd: commands) {
        if (cmd.action.compare("forward")==0) {
            position+=cmd.value;
        }
        else if (cmd.action.compare("down")==0) {
            depth+=cmd.value;
        }
        else if (cmd.action.compare("up")==0) {
            depth-=cmd.value;
        } else break;
    }
    cout << endl << "Part #1" << endl;
    cout << "Final position: " << position << endl;
    cout << "Depth: " << depth << endl;
    cout << "Response: " << depth*position << endl << endl;
}

void Dive::part2()
{
    int aim = 0;
    unsigned position = 0;
    int depth = 0;

    for (auto &cmd: commands) {
        if (cmd.action.compare("forward")==0) {
            position += cmd.value;
            depth += aim * cmd.value;
        }
        else if (cmd.action.compare("down")==0) {
            aim += cmd.value;
        }
        else if (cmd.action.compare("up")==0) {
            aim -= cmd.value;
        } else break;
    }
    cout << endl << "Part #2" << endl;
    cout << "Final position: " << position << endl;
    cout << "Depth: " << depth << endl;
    cout << "Response: " << depth*position << endl;
}

