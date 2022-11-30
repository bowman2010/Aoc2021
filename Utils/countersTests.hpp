#include <itemCounter.h>
#include <check.h>

using namespace std;

void test_Add_Count()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA");
    ic1.add("BB",99);

    CHECK(ic1.count("AA")==1);
    CHECK(ic1.count("BB")==99);
}

void test_remove()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA");
    ic1.add("BB",99);
    ic1.remove("AA");
    ic1.remove("BB",90);

    CHECK(ic1.count("AA")==0);
    CHECK(ic1.count("BB")==9);
}

void test_removeAll()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA");
    ic1.add("BB",99);
    ic1.removeAll("BB");
    CHECK(ic1.count("BB")==0);
}

void test_clear()
{
    bml::ItemCounter<string> ic1;
    ic1.add("AA");
    ic1.add("BB",99);
    CHECK(ic1.itemsCount()==2);

    ic1.clear();
    CHECK(ic1.itemsCount()==0);
}

void test_HighLow()
{
    bml::ItemCounter<string> ic1;

    ic1.add("AA");
    ic1.add("BB",99);
    ic1.add("CC",24);

    unsigned l = ic1.min();
    unsigned h = ic1.max();
    unsigned m = ic1.mean();

    cout << "low  =" << l << endl;
    cout << "high =" << h << endl;
    cout << "mean =" << m << endl;
//    cout << ic1.low() << endl;

//    ic1.clear();
//    CHECK(ic1.low()==0);

}

void counterTests()
{
    test_Add_Count();
    test_remove();
    test_removeAll();
    test_clear();
    test_HighLow();
}

