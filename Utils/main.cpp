#include <iostream>
#include <string>
#include <itemCounter.h>

using namespace std;


int main()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA");
    ic1.add("AA");
    ic1.add("BB");
    ic1.add("CC");
    cout << " count(AA) : " << ic1.count("AA") << endl;
    cout << " count(BB) : " << ic1.count("BB") << endl;
    cout << " count(CC) : " << ic1.count("CC") << endl;

    cout << "removing AA and BB" << endl;
    ic1.remove("AA"); ic1.remove("BB");
    cout << " count(AA)  : " << ic1.count("AA") << endl;
    cout << " count(BB) : " << ic1.count("BB") << endl;

    cout << "removing AA and BB" << endl;
    ic1.remove("AA"); ic1.remove("BB");
    cout << " count(AA)  : " << ic1.count("AA") << endl;
    cout << " count(BB) : " << ic1.count("BB") << endl;

    return 0;
}
