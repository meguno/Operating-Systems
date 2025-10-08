#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "employee.h"
using namespace std;

int main(int argc, char* argv[]) {
    string binaryFileName = argv[1];
    string reportFileName = argv[2];
    double hourlyRate = atof(argv[3]);

    ifstream fin(binaryFileName, ios::binary);
    if (!fin) {
        cerr << "Cannot open binary file!" << endl;
        return 1;
    }

    ofstream reportFile(reportFileName);
    if (!reportFile) {
        cerr << "Cannot open report file for writing!" << endl;
        return 1;
    }

    reportFile << "Output file \"" << binaryFileName << "\"" << endl;
    reportFile << "Info Number  Name  Hours  Salary" << endl;

    employee emp;
    while (fin.read(reinterpret_cast<char*>(&emp), sizeof(employee))) {
        double salary = emp.hours * hourlyRate;
        reportFile << setw(15) << emp.num
            << setw(15) << emp.name
            << setw(10) << emp.hours
            << setw(10) << salary << endl;
    }

    fin.close();
    reportFile.close();

    return 0;
}