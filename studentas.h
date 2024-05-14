#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:

    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() {}

    virtual void setVardas(const string& vardas) { vardas_ = vardas; }
    virtual void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    virtual string getVardas() const = 0; // { return vardas_; }
    virtual string getPavarde() const = 0; // { return pavarde_; }   
};

class Studentas : public Zmogus {
private:
    vector<int> pazymiai_;
    int egzamino_rezultatas_;
    double galutinis_vid_, mediana_;

public:
    Studentas() : egzamino_rezultatas_(0), galutinis_vid_(0), mediana_(0) {}
    Studentas(const vector<int>& pazymiai, const string& vardas, const string& pavarde, int egzamino_rezultatas, double galutinis_vid, double mediana) 
        : Zmogus(vardas, pavarde), pazymiai_(pazymiai), egzamino_rezultatas_(egzamino_rezultatas), galutinis_vid_(galutinis_vid), mediana_(mediana) {}

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other.getVardas(), other.getPavarde()), pazymiai_(other.pazymiai_), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {}

    // Copy assignment
    Studentas& operator = (const Studentas& other)
    {
        if (this != &other) {
            Zmogus::setVardas(other.getVardas());
            Zmogus::setPavarde(other.getPavarde());
            pazymiai_ = other.pazymiai_;
            egzamino_rezultatas_ = other.egzamino_rezultatas_;
            galutinis_vid_ = other.galutinis_vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : Zmogus(move(other.vardas_), move(other.pavarde_)), pazymiai_(move(other.pazymiai_)), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {other.egzamino_rezultatas_ = 0; other.galutinis_vid_ = 0;
        other.mediana_ = 0; }

    // Move assignment 
    Studentas& operator = (Studentas&& other) noexcept
    {
        if (this != &other) {
            Zmogus::setVardas(move(other.getVardas()));
            Zmogus::setPavarde(move(other.getPavarde()));
            pazymiai_ = move(other.pazymiai_);
            egzamino_rezultatas_ = other.egzamino_rezultatas_;
            galutinis_vid_ = other.galutinis_vid_;
            mediana_ = other.mediana_;
            other.egzamino_rezultatas_ = 0;
            other.galutinis_vid_ = 0;
            other.mediana_ = 0;
        }
        return *this;
    }

    ~Studentas() {pazymiai_.clear();}

    void setVardas(const string& vardas) override { Zmogus::setVardas(vardas); }
    void setPavarde(const string& pavarde) override { Zmogus::setPavarde(pavarde); }
    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    void setGalutinisVid(double galutinis_vid) { galutinis_vid_ = galutinis_vid; }
    void setMediana(double mediana) { mediana_ = mediana; }

    string getVardas() const override { return vardas_; }
    string getPavarde() const override { return pavarde_; }
    const vector<int>& getPazymiai() const { return pazymiai_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getMediana() const { return mediana_; }

    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }

    // Input
    friend istream& operator>>(istream& is, Studentas& studentas) {
    
        is >> studentas.vardas_ >> studentas.pavarde_;

        int pazymys;
        studentas.pazymiai_.clear();
        while(is >> pazymys && pazymys > 0 && pazymys <= 10 ) {
            studentas.addPazymys(pazymys);
        }

        is >> studentas.egzamino_rezultatas_;

        return is;
    }

    // Output
    friend ostream& operator<<(ostream& os, const Studentas& studentas) {
        os << "Studento informacija:" << endl;
        os << "Vardas: " << studentas.vardas_ << endl;
        os << "Pavarde: " << studentas.pavarde_ << endl;
        os << "Galutinis vidurkis: " << studentas.galutinis_vid_ << endl;
        return os;
    }

    };

#endif