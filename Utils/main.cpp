#include <iostream>
#include <string>
#include <itemCounter.h>

using namespace std;


int main()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA",2);
    ic1.add("BB",2);
    ic1.add("CC",3);
    ic1.add("DD",4);
    ic1.add("EE",4);

    ic1.remove("AA");
    ic1.removeAll("BB",false);
    ic1.remove("CC",4,false);
    ic1.remove("DD",4);
    ic1.remove("EE",56);

    return 0;
}
