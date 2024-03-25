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

    public:
        // Konstruktorius
        Studentas() : egzamino_rezultatas_(0), galutinis_vid_(0), mediana_(0) {}

    // Metodai
    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    double galBalas(double (*funkcija)(vector<int>) = mediana) const;
    istream& readStudent(istream&);
};

bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);

#endif