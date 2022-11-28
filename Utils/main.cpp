#include <iostream>
#include <string>
#include <strUtils.h>
#include <containerUtils.h>

using namespace std;

int main()
{
    string s("az,SANTA,sdzeze,abcdefgh,azeaze");
    vector<string> vs = bml::splitStr(s,',');
    cout << "v      : " << bml::vec2str(vs,'|') << endl;

    vector<vector<int>> vi;
    for (int i=0; i<10; i++)
    {
        vector<int> vr;
        for (int j=0; j<10; j++)
        {
            vr.push_back(i*10+j);
        }
        vi.push_back(vr);
    }
    cout << "longest:" << bml::longestInVec(vi) << endl;
    return 0;
}
