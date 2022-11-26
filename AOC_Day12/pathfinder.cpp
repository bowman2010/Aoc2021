#include "pathfinder.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>


PathFinder::PathFinder(string fname)
{
    std::fstream inf(fname);
    std::string pathLine;

    string cave1, cave2;
    while (getline(inf,pathLine) && !pathLine.empty())
    {
        stringstream ss1(pathLine);
        getline(ss1,cave1,'-');
        getline(ss1,cave2);

        // Note that no destination back to start cave
        if (cave2.compare("start")) connections.insert(make_pair(cave1,cave2));
        if (cave1.compare("start")) connections.insert(make_pair(cave2,cave1));
    }
}

void PathFinder::findPaths(Cave cave, Path cpath, map<Cave,unsigned> visitCount)
{
    cpath.push_back(cave);
    if (cave.compare("end")==0) {
        savePath(cpath);
        return;
    }

    if (!visitCount.contains(cave)) visitCount.insert(make_pair(cave,1));
        else visitCount.at(cave)++;

    unsigned mx1;
    if (cave.compare(extraTicket)==0) mx1=2; else mx1=1;
    if (islower(cave[0]) && visitCount.at(cave) > mx1) return;

    auto range = connections.equal_range(cave);
    for (auto i = range.first; i != range.second; ++i)
    {
        findPaths(i->second,cpath,visitCount);
    }
}

void PathFinder::findPaths2(Cave cave)
{
    set<Cave> extraTickets; // which caves can be visited more than 1 time
    savedPaths.clear();
    for (auto cnx: connections)
    {
        if (islower(cnx.first[0])) extraTickets.insert(cnx.first);
        if (islower(cnx.second[0])) extraTickets.insert(cnx.first);
    }

    for (auto xtra: extraTickets)
    {
        extraTicket = xtra;
        findPaths("start");
    }
}

void PathFinder::savePath(Path path)
{
    stringstream oss;
    auto itr = path.begin();
    while (itr<path.end()-1) {
        oss << *itr << ",";
        itr++;
    }
    savedPaths.insert(oss.str());
}

void PathFinder::printPaths()
{
    unsigned n = 0;
    for (string p: savedPaths) {
        cout << "Path #" << setw(5) << n << " " << p << endl;
    }
}

unsigned PathFinder::getPathCount() const
{
    return savedPaths.size();
}
