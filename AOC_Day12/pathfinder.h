#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

using Cave = string;
using Path = vector<string>;

class PathFinder
{
    multimap<Cave,Cave> connections;
    set<string> savedPaths;
    Cave extraTicket = ""; // cave that can be visited more than 1 time
public:
    PathFinder(string fname);
    void findPaths(Cave cave = "start",
                   Path cpath = Path(),
                   map<Cave,unsigned> visitCount = map<Cave,unsigned>());
    void findPaths2(Cave cave="start");
    void savePath(Path path);
    void printPaths();
    unsigned getPathCount() const;
};

#endif // PATHFINDER_H
