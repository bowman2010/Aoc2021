#ifndef VENT_H
#define VENT_H


#include <ostream>
#include <vector>
class Vent
{
    int ax,ay,bx,by;

public:
    Vent();
    Vent(int ax,int ay,int bx,int by);
    bool isHorizontal();
    bool isVertical();
    bool isDiagonal();
    std::vector<std::pair<int,int>> points();

    friend std::ostream &operator<<( std::ostream &output, const Vent &vent );
    friend std::istream &operator>>( std::istream &input, Vent &vent );
    int getAx() const;
    int getAy() const;
    int getBx() const;
    int getBy() const;
};

#endif // VENT_H
