#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include "funkcijos.h"

using namespace std;

class Studentas {
private:
    vector<int> pazymiai_;
    string vardas_;
    string pavarde_;
    int egzamino_rezultatas_;

public:
    // Konstruktorius
    Studentas() : egzamino_rezultatas_(0) {}
    Studentas(std::istream& is);

    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    
    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    vector<int> getPazymiai() const { return pazymiai_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }

    istream& readStudent(istream& in);

    // Galutinio balo skaiciavimas
    double galBalas(double (*funkcija)(vector<int>), int egzamino_rezultatas) const;
};

#endif


