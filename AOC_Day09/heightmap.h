#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include <string>
#include <vector>
#include <utility>
#include <sstream>

struct Coord {
    int x,y;
    Coord(int x, int y) : x(x), y(y) {};
    std::string str() {
        std::stringstream ss;
        ss << "(" << x << "," << y << ")";
        return ss.str();
    }
};

class HeightMap
{
    int mapWidth;
    int mapHeight;
    std::vector<std::vector<int>> hmap;
    std::vector<Coord> lowPoints;
public:
    HeightMap(std::string fname);
    void loadMap(std::string fname);
    void findLowPoints();
    bool isLow(int x, int y);
    int  calcRisk();
    void findBassins();
};

#endif // HEIGHTMAP_H
