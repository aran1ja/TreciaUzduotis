#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

using namespace std;

class Studentas {
    private: 
        vector<int> pazymiai;
        string vardas_;
        string pavarde_;
        int egzamino_rezultatas_;
        double galutinis_vid_;
        double mediana_;
};

#endif