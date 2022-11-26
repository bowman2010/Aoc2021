#include "bdiagnostic.h"
#include <fstream>
#include <iostream>
#include <iomanip>

BDiagnostic::BDiagnostic(string fname)
{
    std::fstream inf(fname);
    std::string diagLine;
    while (getline(inf,diagLine) && !diagLine.empty())
    {
        data.push_back(DataRecord(diagLine));
    }
}

void BDiagnostic::part1()
{
    int gamma = 0;
    int epsilon = 0;

    cout << "Part #1" << endl;
    cout << "Binary diag : ";

    calcBitStats();

    for(int i=0; i<DATAWIDTH; i++) {
        gamma=gamma*2;
        epsilon = epsilon*2;
        if (ones[i]>zeroes[i]) {
            cout << "1";
            gamma++;
        } else  {
            cout << "0";
            epsilon++;
        }
    }
    cout << endl;
    cout << "Gamma conversion   = " << gamma << endl;
    cout << "Epsilon conversion = " << epsilon << endl;
    cout << "Response (Gamma*Epsilon) = " << gamma*epsilon << endl;
}

void BDiagnostic::part2()
{
    int bitNr;
    cout << "Part #2" << endl;
    cout << "--------------------------" << endl;
    cout << "     CHECKING Oxygen" << endl ;
    cout << "--------------------------" << endl;
    selectAll();
    bitNr=0;
    while (selected>1 && bitNr<12) {
        calcBitStats();
        showStats();
        if (ones[bitNr]>=zeroes[bitNr])
             filterOut(bitNr,'0');
        else filterOut(bitNr,'1');
        bitNr++;
    }
    showStats();
    auto ptr = data.begin();
    while (ptr<data.end() && !ptr->selected) ptr++;
    string o2str= ptr->bin;


    // Check CO2
    cout << "--------------------------" << endl;
    cout << "     CHECKING CO2" << endl ;
    cout << "--------------------------" << endl;
    selectAll();
    bitNr = 0;
    while (selected>1 && bitNr<12) {
        if (selected<5) showSelected();
        calcBitStats();
        showStats();
        if (ones[bitNr]>=zeroes[bitNr])
             filterOut(bitNr,'1');
        else filterOut(bitNr,'0');
        bitNr++;
    }
    showStats();

    ptr = data.begin();
    while (ptr<data.end() && !ptr->selected) ptr++;
    string co2str = ptr->bin;


    int co2int = bitstr2int(co2str);
    int o2int = bitstr2int(o2str);
    cout << " O2 : " << o2str << "(" << o2int << ")" << endl;
    cout << "CO2 : " << co2str << "(" << co2int << ")" << endl;
    cout << "Response = " << co2int*o2int << endl;

}

void BDiagnostic::selectAll()
{
    selected = data.size();
    for (auto &d : data) {
        d.selected = true;
    }
}

void BDiagnostic::calcBitStats()
{
    for (int i=0; i<DATAWIDTH; i++) {
        ones[i]=0;
        zeroes[i]=0;
    }

    for (DataRecord &rec : data) {
        if (rec.selected==true) { // Check only selected record
            for (int i=0; i<DATAWIDTH; i++) {
                if (rec.bin[i]=='0') zeroes[i]++;
                if (rec.bin[i]=='1') ones[i]++;
            }
        }
    }
}

void BDiagnostic::showStats()
{
    cout << endl << endl;
    cout << "Statistics" << endl;
    cout << "Records: " << data.size()
         << "  selected: " << selected
         << " filtered: " << filtered;
    cout << endl;
    cout << "BitNr      Zeroes     Ones" << endl;
    for (int i=0; i<DATAWIDTH; i++) {
        cout << std::left << std::setw(10) << i;
        cout << std::right << std::setw(10) << zeroes[i];
        cout << std::right << std::setw(10) << ones[i] << endl;
    }
    cout << endl << endl;
}

void BDiagnostic::showSelected()
{
    cout << endl << "Selection:" << endl;
    for (DataRecord &rec : data) {
        if (rec.selected)
            cout <<  rec.bin << endl;
    }
}

void BDiagnostic::filterOut(int bitNr, char value)
{
    for (DataRecord &rec : data) {
        if (rec.selected && rec.bin[bitNr]==value) {
            rec.selected = false;
            filtered++;
            selected--;
        }
    }
}

int BDiagnostic::bitstr2int(string bitstr)
{
    int n = 0;
    int w = bitstr.length();
    for (int i=0; i<w; i++) {
        n = n<<1;
        if (bitstr[i]=='1') n+=1;
    }
    return n;
}

