#include "vent.h"
#include <sstream>

int Vent::getAx() const
{
    return ax;
}

int Vent::getAy() const
{
    return ay;
}

int Vent::getBx() const
{
    return bx;
}

int Vent::getBy() const
{
    return by;
}

Vent::Vent()
{
    ax=0; ay=0; bx=0; by=0;
}

Vent::Vent(int ax, int ay, int bx, int by)
{
    this->ax = ax;
    this->ay = ay;
    this->bx = bx;
    this->by = by;
}

bool Vent::isHorizontal()
{
    return ay==by;
}

bool Vent::isVertical()
{
    return ax==bx;
}

bool Vent::isDiagonal()
{
    return !((ax==bx)||(ay==by));
}

std::ostream &operator<<( std::ostream &output, const Vent &vent )
{
    output << "Vent(" << vent.ax << "," << vent.ay << " -> " << vent.bx << "," << vent.by << ")";
    return output;
}

std::istream &operator>>( std::istream &input, Vent &vent )
{
    char virg;
    std::string arrow;

    std::string lineStr;
    std::getline(input,lineStr);
    std::istringstream iss(lineStr);
    iss >> vent.ax;
    iss >> virg;
    iss >> vent.ay;
    iss >> arrow;
    iss >> vent.bx;
    iss >> virg;
    iss >> vent.by;

    return input;
}
