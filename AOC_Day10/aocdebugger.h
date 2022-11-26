#ifndef AOCDEBUGGER_H
#define AOCDEBUGGER_H
#include <string>
#include <vector>

using namespace std;

class AocDebugger
{
    vector<string>  program;
    vector<bool>    errorFlags;
    int errorScore = 0;
    vector<int> autocompScores;

    const string opening = "([{<";
    const string closing = ")]}>";
public:
    AocDebugger(string fname);
    void checkPairs();
    void completeLines();
    int completeLine(string codeLine);
};

#endif // AOCDEBUGGER_H
