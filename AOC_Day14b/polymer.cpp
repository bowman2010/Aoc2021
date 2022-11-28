#include "polymer.h"
#include "check.h"
#include <sstream>
#include <fstream>

Polymer::Polymer(string fname)
{
    string s1,s2;
    std::fstream inf(fname);
    CHECK(inf);
    inf >> polymer0;

    string rulep1,rulep2;
    while (getline(inf,s1))
    {
        if (!s1.empty()) {
            stringstream ss1(s1);
            ss1 >> rulep1;
            ss1 >> s2;
            ss1 >> rulep2;
            rules.insert(make_pair(rulep1,rulep2));
        }
    }
    cout << "Puzzle Loaded" << endl;
    cout << "Polymer zero : " << polymer0 << endl;
    cout << "Rules:" << endl;
    for (auto &rule : rules){
        cout << "  " << rule.first << " => " << rule.second << endl;
    }
}
