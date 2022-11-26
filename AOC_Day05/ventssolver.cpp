#include "ventssolver.h"
#include <fstream>
#include <iostream>
#include <iomanip>

VentsSolver::VentsSolver(std::string puzzlePath)
{
    std::ifstream fin(puzzlePath);
    while (true) {
        Vent v;
        fin >> v;
        if (fin.eof()) break;
        vents.push_back(v);
    }
    std::cout << "Loaded " << vents.size() << " Vents" << std::endl;
}

void VentsSolver::resetMap()
{
    for (unsigned x=0; x<MAP_SZE; x++) {
        for (unsigned y=0; y<MAP_SZE; y++) {
            map[x][y] = 0;
        }
    }
}

int VentsSolver::count()
{
    unsigned counter = 0;
    for (int i=0; i<MAP_SZE; i++) {
        for (int j=0; j<MAP_SZE; j++) {
            if (map[i][j] >= 2) counter++;
        }
    }
    return counter;
}

void VentsSolver::part1()
{
    resetMap();

    for (unsigned i=0; i<vents.size(); i++) {

        if (vents[i].isHorizontal()) {
            int fx = vents[i].getAx();
            int tx = vents[i].getBx();
            if (fx>tx) { auto tmp=fx; fx=tx; tx=tmp; }
            int y = vents[i].getAy();
            for (int x=fx; x<=tx; x++) {
                map[x][y]++;
            }
        }
        else
        if (vents[i].isVertical()) {
                int fy = vents[i].getAy();
                int ty = vents[i].getBy();
                if (fy>ty) { auto tmp=fy; fy=ty; ty=tmp; }
                int x = vents[i].getAx();
                for (int y=fy; y<=ty; y++) {
                    map[x][y]++;
                }
        }
    }
    std::cout << "H+V = " << count() << std::endl;

    // Add diagonal lines
    for (unsigned i=0; i<vents.size(); i++) {
        if (vents[i].isDiagonal()) {
            int ax = vents[i].getAx();
            int ay = vents[i].getAy();
            int bx = vents[i].getBx();
            int by = vents[i].getBy();

            if (ax>bx) {
                std::swap(ax,bx);
                std::swap(ay,by);
            }
            int dir = 1;
            if (ay>by) dir = -1;

            int y=ay;
            for (auto x=ax; x<=bx; x++) {
                map[x][y]++;
                y+=dir;
            }
        }
    }
    std::cout << "H+V+D = " << count() << std::endl;

}
