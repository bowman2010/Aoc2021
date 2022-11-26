#ifndef VENTSSOLVER_H
#define VENTSSOLVER_H

#include <array>
#include <vector>
#include "vent.h"

#define MAP_SZE     1000

class VentsSolver
{
    std::array<std::array<int,MAP_SZE>,MAP_SZE> map;
    std::vector<Vent> vents;
public:
    VentsSolver(std::string puzzlePath);
    void part1();
    void resetMap();
    int count();
};

#endif // VENTSSOLVER_H
