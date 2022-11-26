#include "polymer.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

Polymer::Polymer(string fname)
{
    string s1;
    std::fstream inf(fname);

    inf >> start;
    inf >> s1;

    while (getline(inf,s1) && !s1.empty())
    {

    }
}
