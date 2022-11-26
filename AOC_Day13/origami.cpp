#include "origami.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;
Origami::Origami(string fname)
{
    string s1,s2;
    ifstream ifs(fname);

    // Load points
    while (getline(ifs,s1) && !s1.empty())
    {
        stringstream iss(s1);
        int px,py;
        getline(iss,s2,','); px = stoi(s2);
        getline(iss,s2,','); py = stoi(s2);
        points.insert(Point2d(px,py));
    }

    // Load actions
    while (getline(ifs,s1) && !s1.empty())
    {
        ActionType atype;
        int value;
        stringstream iss(s1);
        getline(iss,s2,'=');
        if (s1.starts_with("fold along y")) atype=FOLDY;
        else if (s1.starts_with("fold along x")) atype=FOLDX;
        else throw "invalid action";
        iss >> value;
        actionsList.push_back(Action(atype,value));
    }
}

void Origami::part1()
{
    cout << "Part 2 :" << endl;
    Action action = actionsList[0];
    switch (action.action) {
        case FOLDX: foldAllAlong_X(action.position); break;
        case FOLDY: foldAllAlong_Y(action.position); break;
    default: break;
    }
    cout << "Points left : " << points.size() << endl << endl;
}

void Origami::part2()
{
    cout << "Part 2 :" << endl;
    for (Action action: actionsList)
    {
        switch (action.action) {
            case FOLDX: foldAllAlong_X(action.position); break;
            case FOLDY: foldAllAlong_Y(action.position); break;
        default: break;
        }
    }
    cout << "Points left : " << points.size() << endl << endl;
}

void Origami::print()
{
#define MAPSIZE 20

    char map[MAPSIZE ][MAPSIZE ];
    for (int x=0; x<MAPSIZE ; x++)
        for (int y=0; y<MAPSIZE ; y++)
            map[y][x] = '.';

    for (Point2d p: points) {
        map[p.y][p.x] = '#';
    }

    for (int y=0; y<MAPSIZE ; y++)
    {
        for (int x=0; x<MAPSIZE ; x++) cout << map[y][x];
        cout << endl;
    }
}


void Origami::foldAllAlong_X(int xfold)
{
//    cout << "---------------------------------------" << endl;
//    cout << "Before fold along X" << endl;
//    print();
    set<Point2d> newPoints;
    for (Point2d p: points) {
        if (p.x > xfold) {
            Point2d newp = p.fold_along_X(xfold);
            newPoints.insert(newp);
        } else newPoints.insert(p);
    }
    points=newPoints;
//    cout << "after" << endl;
//    print();
//    cout << "---------------------------------------" << endl;
}

void Origami::foldAllAlong_Y(int yfold)
{
//    cout << "---------------------------------------" << endl;
//    cout << endl << "Before fold along Y" << endl;
//    print();
    set<Point2d> newPoints;
    for (Point2d p: points) {
        if (p.y > yfold) {
            Point2d newp = p.fold_along_Y(yfold);
            newPoints.insert(newp);
        } else newPoints.insert(p);
    }
    points=newPoints;
//    cout << "after" << endl;
//    print();
//    cout << "---------------------------------------" << endl;
}


Point2d::Point2d(int x, int y) : x(x), y(y) {}

Point2d Point2d::fold_along_X(int xfold)
{
    return Point2d(xfold-abs(x-xfold),y);
}

Point2d Point2d::fold_along_Y(int yfold)
{
    return Point2d(x,yfold-abs(y-yfold));
}

bool Point2d::operator == (const Point2d &p) const
{
    return this->x==p.x && this->y==p.y;
}

bool Point2d::operator <(const Point2d &p) const
{
    return this->x!=p.x || this->y!=p.y;
}

