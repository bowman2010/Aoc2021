#ifndef ORIGAMI_H
#define ORIGAMI_H

#include <string>
#include <vector>
#include <set>

using namespace std;

struct Point2d {
public:
    int x;
    int y;
    Point2d(int x, int y);
    Point2d fold_along_X(int xfold);
    Point2d fold_along_Y(int yfold);
    bool operator == (const Point2d &p) const;
    bool operator < (const Point2d &p) const;
};

enum ActionType {
    FOLDX,
    FOLDY,
};

struct Action {
    ActionType action;
    int position;
    Action(ActionType action, int position)
        : action(action), position(position) {}
};

class Origami
{
    set<Point2d> points;
    vector<Action> actionsList;
public:
    Origami(string fname);
    void part1();
    void part2();
    void print();
private:
    void foldAllAlong_X(int xfold);
    void foldAllAlong_Y(int yfold);

};

#endif // ORIGAMI_H
