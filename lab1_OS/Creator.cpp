#include <iostream>
#include <fstream>
#include <cstring>
#include "employee.h"
using namespace std;

int main(int argc, char* argv[]) {
    string filename = argv[1];
    int numRecords = atoi(argv[2]);
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cerr << "Failed to create file." << endl;
        return 1;
    }
    for (int i = 0; i < numRecords; ++i) {
        employee emp;
        cout << "Enter employee number: ";
        cin >> emp.num;
        cin.ignore();
        cout << "Enter employee name: ";
        cin.getline(emp.name, 10);
        cout << "Enter hours worked: ";
        cin >> emp.hours;
        fout.write(reinterpret_cast<const char*>(&emp), sizeof(employee));
    }
    fout.close();
    return 0;
}