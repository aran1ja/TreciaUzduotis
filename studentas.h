#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

using namespace std;

class Studentas {

    public:
    vector<int> pazymiai;
    string vardas, pavarde;
    int egzamino_rezultatas;
    double galutinis_vid, mediana;

    Studentas() : egzamino_rezultatas(0), galutinis_vid(0), mediana(0) {}
    Studentas(const vector<int>& pazymiai, string vardas, string pavarde, int egzamino_rezultatas, double galutinis_vid, double mediana) 
        : pazymiai(pazymiai), vardas(vardas), pavarde(pavarde), egzamino_rezultatas(egzamino_rezultatas), galutinis_vid(galutinis_vid), mediana(mediana) {}

    ~Studentas() {}
};

#endif
