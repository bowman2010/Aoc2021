#ifndef BDIAGNOSTIC_H
#define BDIAGNOSTIC_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

#define DATAWIDTH 12

struct DataRecord {
    bool selected;
    string bin;
    DataRecord(string s) : selected(true), bin(s) {};
};

class BDiagnostic
{
public:
    BDiagnostic(string fname);

    void part1();
    void part2();
private:
    std::vector<DataRecord> data;
    int selected;
    int filtered = 0;
    int ones[DATAWIDTH];
    int zeroes[DATAWIDTH];

    void selectAll();       // Set all records as selected
    void calcBitStats();    // Calculate bits statistics (sum) for all selected records
    void showStats();       // Display statistics for debugging
    void showSelected();    // Display selected records for debugging
    void filterOut(int bitNr, char value); // Unselect all records that have bitNr set to value
    int bitstr2int(std::string bitstr); // convert bitstring to integer
};

#endif // BDIAGNOSTIC_H
