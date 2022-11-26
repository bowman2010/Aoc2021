#include "aocdebugger.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>

AocDebugger::AocDebugger(string fname)
{
    std::fstream inf(fname);
    std::string codeLine;
    while (getline(inf,codeLine) && !codeLine.empty())
    {
        program.push_back(codeLine);
    }
    cout << "Debugger loaded " << program.size() << " lines" << endl;
}

void AocDebugger::checkPairs()
{
    stack<char> stk1;
    int lineCounter = 1;
    errorScore = 0;

    for (auto &codeLine: program) {
        int charCounter = 1;
        bool hasError = false;
        for(char ch : codeLine) {
            size_t ocharIdx = opening.find(ch);
            size_t ccharIdx = closing.find(ch);

            if (ocharIdx!=string::npos) { // Its an opening char
                stk1.push(ch);
            }

            if (ccharIdx!=string::npos) { // Its an closing char
                char top = stk1.top();
                size_t shouldBeIdx = opening.find(top);
                if (ccharIdx!=shouldBeIdx) {
                    hasError = true;
//                    cout << "[" << lineCounter << "] " << codeLine << endl;
//                    cout << "Error position " << lineCounter << "," << charCounter << " ";
//                    cout << "Expected " << closing[shouldBeIdx ] << " found " << ch << " instead" << endl;
                    switch (ch) {
                        case ')': errorScore+=3;     break;
                        case ']': errorScore+=57;    break;
                        case '}': errorScore+=1197;  break;
                        case '>': errorScore+=25137; break;
                        default: break;
                    }
                }
                stk1.pop();
            }
            charCounter++;
        }
        errorFlags.push_back(hasError);
        lineCounter++;
    }
    cout << "Error score = " << errorScore << endl;
}

void AocDebugger::completeLines()
{
    for (size_t i=0; i<program.size(); i++) {
        if (!errorFlags[i]) {
            int acScore = completeLine(program[i]);
            autocompScores.push_back(acScore);
        }
    }
    cout << "Middle autocompl score : ";
    sort(autocompScores.begin(),autocompScores.end());
    size_t acMidIdx = (autocompScores.size()+1)/2;
    cout << autocompScores[acMidIdx] << endl;
}


int AocDebugger::completeLine(string codeLine)
{
    stack<char> stk1;

//    cout << codeLine << " --- ";
    for(char ch : codeLine) {
        size_t ocharIdx = opening.find(ch);
        size_t ccharIdx = closing.find(ch);

        if (ocharIdx!=string::npos) { // Its an opening char
            stk1.push(ch);
        }
        if (ccharIdx!=string::npos) { // Its an closing char
            stk1.pop();
        }
    }

    int compScore = 0;
    while (!stk1.empty()) {
        char c = stk1.top();
        stk1.pop();
        auto cIdx = opening.find(c);
        char matchc = closing[cIdx];
        switch (matchc) {
            case ')': compScore = compScore*5 + 1; break;
            case ']': compScore = compScore*5 + 2; break;
            case '}': compScore = compScore*5 + 3; break;
            case '>': compScore = compScore*5 + 4; break;
            default: break;
        }
//        cout << matchc;
    }
//    cout << endl;
    return compScore;
}
