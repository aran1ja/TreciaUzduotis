#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

using namespace std;

struct Studentas {
    vector<int> pazymiai;
    string vardas, pavarde;
    int egzamino_rezultatas;
    double galutinis_vid, mediana;
};

#endif