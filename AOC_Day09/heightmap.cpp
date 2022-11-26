#include "heightmap.h"

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>


HeightMap::HeightMap(std::string fname)
{
    loadMap(fname);
}

void HeightMap::loadMap(std::string fname)
{
    // Delete lowpoints
    lowPoints.clear();
    // Delete old map
    hmap.clear();

    std::fstream inf(fname);
    std::string mapLine;
    size_t lineNr = 0;
    while (getline(inf,mapLine) && !mapLine.empty())
    {
        std::vector<int> lineV;
        for (auto &ch : mapLine)
        {
            lineV.push_back(ch-'0');
        }
        hmap.push_back(lineV);
        lineNr++;
    }
    mapHeight = hmap.size();
    mapWidth  = hmap[0].size();
}

void HeightMap::findLowPoints()
{
    lowPoints.clear();
    for (auto y=0; y<mapHeight; y++) {
        for (auto x=0; x<mapWidth; x++) {
            if (isLow(x,y)) lowPoints.push_back(Coord(x,y));
        }
    }

//    std::cout << "Found lowpoints : ";
//    for (auto lowp: lowPoints) {
//        std::cout << lowp.str() << " ";
//    }
//    std::cout << std::endl;

}

bool HeightMap::isLow(int x, int y)
{
    int v=hmap[y][x];
    // If not 1st row(y) check above
    if ((y>0) && hmap[y-1][x]<=v) return false;

    // If not last row(y) check below
    if ((y<mapHeight-1) && hmap[y+1][x]<=v) return false;

    // If not 1st col(x) check left
    if ((x>0) && hmap[y][x-1]<=v) return false;

    // If not last col(x) check right
    if ((x<mapWidth-1) && hmap[y][x+1]<=v) return false;

    return true;
}

int HeightMap::calcRisk()
{
    int risk = 0;
    for (auto p: lowPoints)
    {
        risk += 1+hmap[p.y][p.x];
    }
    std::cout << "Risk = " << risk << std::endl;
    return risk;
}

void HeightMap::findBassins()
{
    // Setup a "visited" map
    std::vector<std::vector<bool>> visited;
    for (int y=0; y<mapHeight; y++) {
        std::vector<bool> row;
        for (int x=0; x<mapWidth; x++) {
            row.push_back(false);
        }
        visited.push_back(row);
    }

    std::vector<int> bSizes;
    for (auto lowp: lowPoints)
    {
        std::queue<Coord> q1;
        int bsize = 0;
        q1.push(lowp);

        while(q1.size()>0) {
            Coord p = q1.front(); q1.pop();
            int v = hmap[p.y][p.x];
            if (!visited[p.y][p.x] && v!=9) {
                if(p.y>0)           q1.push(Coord(p.x,   p.y-1 ));
                if(p.y<mapHeight-1) q1.push(Coord(p.x,   p.y+1 ));
                if(p.x>0)           q1.push(Coord(p.x-1, p.y   ));
                if(p.x<mapWidth-1)  q1.push(Coord(p.x+1, p.y   ));
                visited[p.y][p.x] = true;
                bsize++;
            }
        }
        bSizes.push_back(bsize);
    }
    sort(bSizes.begin(),bSizes.end(),std::greater <>());
    std::cout << "3 Biggest bassins: ";
    int resp = 1;
    for (int i=0; i<3; i++) {
        std::cout << bSizes[i] << " ";
        resp *= bSizes[i];
    }
    std::cout << std::endl << "response = " << resp << std::endl;

}

