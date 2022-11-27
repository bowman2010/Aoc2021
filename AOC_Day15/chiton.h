#ifndef CHITON_H
#define CHITON_H

#include <string>
#include <vector>
#include <climits>

using namespace std;

struct Coord {
    unsigned x;
    unsigned y;
    Coord(unsigned x, unsigned y);
    bool operator == (const Coord& other) const;
    bool operator != (const Coord& other) const;
    vector<Coord>adjacents4() const;
    vector<Coord>adjacentsDR() const;
    friend ostream &operator << (ostream &output, const Coord& coord);
};

class Chiton
{
    vector<vector<unsigned>> map;
    vector<vector<bool>> visited;

    unsigned mapWidth = 0;
    unsigned mapHeight = 0;
    unsigned lowestRiskFound = UINT_MAX;
    const Coord startPoint{0,0};
    Coord endPoint{0,0};
    bool debug = true;
public:
    Chiton(string fname);
    void part1();
    void lowestRisk(Coord coord, unsigned risk=0);

    bool validCoord(const Coord &coord) const;
    unsigned mapAt(const Coord &coord) const;
    void setVisited(const Coord &coord, bool v=true);
    bool isVisited(const Coord &coord) const;
};

#endif // CHITON_H
