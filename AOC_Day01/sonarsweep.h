#ifndef SONARSWEEP_H
#define SONARSWEEP_H
#include <string>
#include <vector>

using namespace std;

class SonarSweep
{
    vector<unsigned> depthProfile;
public:
    SonarSweep(string fname);
    void part1();
    void part2();
};

#endif // SONARSWEEP_H
