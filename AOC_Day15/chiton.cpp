#include "chiton.h"
#include "check.h"
#include <fstream>

Chiton::Chiton(string fname)
{
    string s1;
    fstream inf(fname);
    CHECK(inf);

    while (getline(inf,s1)&& !s1.empty()) {
        vector<unsigned> row;
        vector<bool> rowv;
        for (unsigned p=0; p<s1.length(); p++)
        {
            row.push_back(s1[p]-'0');
            rowv.push_back(false);
        }
        map.push_back(row);
        visited.push_back(rowv);
    }
    mapHeight = map.size();
    mapWidth = map[0].size();
    endPoint = Coord(mapWidth-1,mapHeight-1);
}

void Chiton::part1()
{
    cout << "part #1" << endl;
    lowestRisk(Coord(0,0));
    cout << "lower risk = " << lowestRiskFound-mapAt(startPoint) << endl;
}

void Chiton::lowestRisk(Coord coord, unsigned risk)
{
    if (risk>lowestRiskFound) {
//        cout << "risk " << risk << "too big" << endl;
        return;
    }
    risk+=mapAt(coord);
    if (coord==endPoint) {
        cout << "reached endpoint with risk " << risk;
        if (risk<lowestRiskFound) {
            cout << " new record !!" << endl;
            lowestRiskFound=risk;
        } else {
            cout << " too big !" << endl;
        }
        return;
    }
    setVisited(coord);

    vector<Coord> adjacents = coord.adjacentsDR();
    for (Coord adjacent: adjacents) {
        if (adjacent!=startPoint && validCoord(adjacent) && !isVisited(adjacent))
        {
            lowestRisk(adjacent,risk);
        }
    }
    setVisited(coord,false);
}

bool Chiton::validCoord(const Coord &coord) const
{
    if (coord.x>=mapWidth || coord.y>=mapHeight) return false;
    return true;
}

unsigned Chiton::mapAt(const Coord &coord) const
{
    return map[coord.y][coord.x];
}

void Chiton::setVisited(const Coord &coord, bool v)
{
    visited[coord.y][coord.x] = v;
}

bool Chiton::isVisited(const Coord &coord) const
{
    return visited[coord.y][coord.x];
}

Coord::Coord(unsigned x, unsigned y)
{
    this->x = x;
    this->y = y;
}

bool Coord::operator ==(const Coord &other) const
{
    return (other.x==this->x) && (other.y==this->y);
}

bool Coord::operator !=(const Coord &other) const
{
    return (other.x!=this->x) || (other.y!=this->y);
}

vector<Coord> Coord::adjacents4() const
{
    vector<Coord> v;
    if (x>0) v.push_back(Coord(x-1,y));
    v.push_back(Coord(x+1,y));
    if (y>0) v.push_back(Coord(x,y-1));
    v.push_back(Coord(x,y+1));
    return v;
}

vector<Coord> Coord::adjacentsDR() const
{
    vector<Coord> v;
    v.push_back(Coord(x,y+1));
    v.push_back(Coord(x+1,y));
    return v;
}

ostream &operator << (ostream &output, const Coord& coord)
{
    output << "(" << coord.x << "," << coord.y << ")";
    return output;
}
