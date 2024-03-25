#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

using namespace std;

class Studentas {
private:
    vector<int> pazymiai_;
    string vardas_, pavarde_;
    int egzamino_rezultatas_;
    double galutinis_vid_, mediana_;

public:
    Studentas() : egzamino_rezultatas_(0), galutinis_vid_(0), mediana_(0) {}
    Studentas(const vector<int>& pazymiai, const string& vardas, const string& pavarde, int egzamino_rezultatas, double galutinis_vid, double mediana) 
        : pazymiai_(pazymiai), vardas_(vardas), pavarde_(pavarde), egzamino_rezultatas_(egzamino_rezultatas), galutinis_vid_(galutinis_vid), mediana_(mediana) {}

    ~Studentas() {}

    const vector<int>& getPazymiai() const { return pazymiai_; }
    const string& getVardas() const { return vardas_; }
    const string& getPavarde() const { return pavarde_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getMediana() const { return mediana_; }

    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    void setGalutinisVid(double galutinis_vid) { galutinis_vid_ = galutinis_vid; }
    void setMediana(double mediana) { mediana_ = mediana; }

    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }
};

#endif
