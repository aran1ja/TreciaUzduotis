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

    double getGalutinis_vid() const {
        int n = pazymiai_.size();
        double suma = 0.0;
        for (int pazymys : pazymiai_) {
            suma += pazymys;
        }
        if (n == 0) {
            return 0.6 * egzamino_rezultatas_;
        } else {
            return 0.4 * (suma / n) + 0.6 * egzamino_rezultatas_;
        }
    }

    double getMediana() const {
        vector<int> kopija = pazymiai_;
        kopija.push_back(egzamino_rezultatas_);
        size_t kiekis = kopija.size();
        sort(kopija.begin(), kopija.end());

        if (kiekis % 2 == 0) {
            return (kopija[kiekis / 2 - 1] + kopija[kiekis / 2]) / 2.0;
        } else {
            return kopija[kiekis / 2];
        }
    }
};

#endif


