#ifndef SEG7_H
#define SEG7_H

#include <string>
#include <vector>

struct NoteLine {
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    NoteLine(const std::string line);
    unsigned count2347();
};

class Seg7
{
    std::vector<NoteLine> notes;
public:
    Seg7(std::string puzzlePath);
    void part1();
};

#endif // SEG7_H
