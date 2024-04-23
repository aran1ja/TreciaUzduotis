#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

/*
class Studentas {
private:
string vardas_, pavarde_;
    vector<int> pazymiai_;
    int egzamino_rezultatas_;
    double galutinis_vid_, mediana_;

public:
    Studentas() : egzamino_rezultatas_(0), galutinis_vid_(0), mediana_(0) {}
    Studentas(string& vardas, string& pavarde, const vector<int>& pazymiai,int egzamino_rezultatas, double galutinis_vid, double mediana) 
        : vardas_(vardas), pavarde_(pavarde), pazymiai_(pazymiai), egzamino_rezultatas_(egzamino_rezultatas), galutinis_vid_(galutinis_vid), mediana_(mediana) {}

    ~Studentas() { pazymiai_.clear(); vardas_.clear(), pavarde_.clear();}

    // Copy constructor
    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), pazymiai_(other.pazymiai_), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {}

    // Copy assignment
    Studentas& operator = (const Studentas& other)
    {
        if (this != &other) {
            pazymiai_ = other.pazymiai_;
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            egzamino_rezultatas_ = other.egzamino_rezultatas_;
            galutinis_vid_ = other.galutinis_vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)), pazymiai_(move(other.pazymiai_)), 
        egzamino_rezultatas_(move(other.egzamino_rezultatas_)), galutinis_vid_(move(other.galutinis_vid_)), mediana_(move(other.mediana_)) {}

    // Move assignment - prideti clear itt
    Studentas& operator = (Studentas&& other) noexcept
    {
        if (this != &other) {
            pazymiai_ = move(other.pazymiai_);
            vardas_ = move(other.vardas_);
            pavarde_ = move(other.pavarde_);
            egzamino_rezultatas_ = other.egzamino_rezultatas_;
            galutinis_vid_ = other.galutinis_vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    const vector<int>& getPazymiai() const { return pazymiai_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getMediana() const { return mediana_; }

    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    void setGalutinisVid(double galutinis_vid) { galutinis_vid_ = galutinis_vid; }
    void setMediana(double mediana) { mediana_ = mediana; }

    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }
    
};*/

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() {}

public:

    virtual void setVardas(const string& vardas) { vardas_ = vardas; }
    virtual void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    virtual string getVardas() const { return vardas_; }
    virtual string getPavarde() const { return pavarde_; }   
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
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {}

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

    string getVardas() const override { return Zmogus::getVardas(); }
    string getPavarde() const override { return Zmogus::getPavarde(); }
    const vector<int>& getPazymiai() const { return pazymiai_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getMediana() const { return mediana_; }

    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }

    // Input
    friend istream& operator>>(istream& is, Studentas& studentas) {
        cout << "Iveskite studento varda: ";
        is >> studentas.vardas_;
        cout << "Iveskite studento pavarde: ";
        is >> studentas.pavarde_;

        int pazymys;
        double suma = 0.0;
        int nd_skaicius = 0;

        do {
            cout << "Iveskite " << nd_skaicius + 1 << " namu darbu pazymi (norint baigti, iveskite -1): ";
            is >> pazymys;

            if (pazymys == -1)
                break;

            while (pazymys < 1 || pazymys > 10 || is.fail()) {
                cout << "Klaida. Iveskite skaiciu nuo 1 iki 10: ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                is >> pazymys;
            }

            studentas.pazymiai_.push_back(pazymys);
            suma += pazymys;
            nd_skaicius++;
        } while (true);

        cout << "Iveskite egzamino rezultata: ";
        is >> studentas.egzamino_rezultatas_;

        while (studentas.egzamino_rezultatas_ < 1 || studentas.egzamino_rezultatas_ > 10 || is.fail()) {
            cout << "Klaida. Iveskite skaiciu nuo 1 iki 10: ";
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            is >> studentas.egzamino_rezultatas_;
        }

        studentas.galutinis_vid_ = (suma / nd_skaicius) * 0.4 + studentas.egzamino_rezultatas_ * 0.6;

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