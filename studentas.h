#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

using namespace std;

class Zmogus {
protected:
    string vardas_;
    string pavarde_;

    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

public:
    virtual ~Zmogus() {}

    const string& getVardas() const { return vardas_; }
    const string& getPavarde() const { return pavarde_; }

    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }

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

    ~Studentas() { pazymiai_.clear(); vardas_.clear(), pavarde_.clear();}

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other), pazymiai_(other.pazymiai_), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {}

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : Zmogus(move(other)), pazymiai_(move(other.pazymiai_)), egzamino_rezultatas_(move(other.egzamino_rezultatas_)), 
        galutinis_vid_(move(other.galutinis_vid_)), mediana_(move(other.mediana_)) {}

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

    // Move assignment
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

    const vector<int>& getPazymiai() const { return pazymiai_; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getMediana() const { return mediana_; }

    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    void setGalutinisVid(double galutinis_vid) { galutinis_vid_ = galutinis_vid; }
    void setMediana(double mediana) { mediana_ = mediana; }

    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }
    
};

#endif