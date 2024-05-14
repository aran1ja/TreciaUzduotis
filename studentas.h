#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

/**
 * @brief Bazinė klasė, aprašanti žmogų.
 */

class Zmogus {
protected:
    string vardas_; /**< Vardo kintamasis */
    string pavarde_; /**< Pavardės kintamasis */

public:

    /**
     * @brief Default konstruktorius.
     */

    Zmogus() = default;
    
    /**
     * @brief Klasės konstruktorius su parametrais.
     * @param vardas Žmogaus vardas
     * @param pavarde Žmogaus pavardė
     */
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

    /**
     * @brief Default destruktorius.
     */
    virtual ~Zmogus() {}

    /**
     * @brief Nustato žmogaus vardą.
     * @param vardas Žmogaus vardas
     */
    virtual void setVardas(const string& vardas) { vardas_ = vardas; }
    
    /**
     * @brief Nustato žmogaus pavardę.
     * @param pavarde Žmogaus pavardė
     */
    virtual void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    
    /**
     * @brief Grąžina žmogaus vardą.
     */
    virtual string getVardas() const = 0; 
    
    /**
     * @brief Grąžina žmogaus pavardę.
     */
    virtual string getPavarde() const = 0;  
};

/**
 * @brief Studento klasė, paveldinti žmogaus savybes.
 */

class Studentas : public Zmogus {
private:
    vector<int> pazymiai_; /**< Pažymių vektorius */
    int egzamino_rezultatas_; /**< Egzamino rezultatas */
    double galutinis_vid_; /**< Galutinio vidurkio rezultatas */
    double mediana_; /**< Medianos rezultatas */

public:

    /**
     * @brief Default konstruktorius.
     */

    Studentas() : egzamino_rezultatas_(0), galutinis_vid_(0), mediana_(0) {}
    Studentas(const vector<int>& pazymiai, const string& vardas, const string& pavarde, int egzamino_rezultatas, double galutinis_vid, double mediana) 
        : Zmogus(vardas, pavarde), pazymiai_(pazymiai), egzamino_rezultatas_(egzamino_rezultatas), galutinis_vid_(galutinis_vid), mediana_(mediana) {}

    /**
     * @brief Copy konstruktorius.
     */

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other.getVardas(), other.getPavarde()), pazymiai_(other.pazymiai_), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {}

    /**
     * @brief Copy assignment opertorius.
     */

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

    /**
     * @brief Move konstruktorius.
     */

    // Move constructor
    Studentas(Studentas&& other) noexcept
        : Zmogus(move(other.vardas_), move(other.pavarde_)), pazymiai_(move(other.pazymiai_)), egzamino_rezultatas_(other.egzamino_rezultatas_), 
        galutinis_vid_(other.galutinis_vid_), mediana_(other.mediana_) {other.egzamino_rezultatas_ = 0; other.galutinis_vid_ = 0;
        other.mediana_ = 0; }

    /**
     * @brief Move assignment operatorius.
     */

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

    /**
     * @brief Destruktorius.
     */

    ~Studentas() {pazymiai_.clear();}

    /**
     * @brief Nustato studento vardą.
     * @param vardas Studento vardas
     */
    void setVardas(const string& vardas) override { Zmogus::setVardas(vardas); }
    
    /**
     * @brief Nustato studento pavardę.
     * @param pavarde Studento pavardė
     */
    void setPavarde(const string& pavarde) override { Zmogus::setPavarde(pavarde); }
    
    /**
     * @brief Nustato studento pažymius.
     * @param pazymiai Studento pažymiai
     */
    void setPazymiai(const vector<int>& pazymiai) { pazymiai_ = pazymiai; }
    
    /**
     * @brief Nustato studento egzamino rezultatą.
     * @param egzamino_rezultatas Studento egzamino rezultatas
     */
    void setEgzaminoRezultatas(int egzamino_rezultatas) { egzamino_rezultatas_ = egzamino_rezultatas; }
    
    /**
     * @brief Nustato studento galutinį vidurkį.
     * @param galutinis_vid Studento galutinis vidurkis
     */
    void setGalutinisVid(double galutinis_vid) { galutinis_vid_ = galutinis_vid; }
    
    /**
     * @brief Nustato studento medianą.
     * @param mediana Studento mediana
     */
    void setMediana(double mediana) { mediana_ = mediana; }


    /**
     * @brief Grąžina studento vardą.
     */
    string getVardas() const override { return vardas_; }
    
    /**
     * @brief Grąžina studento pavardę.
     */
    string getPavarde() const override { return pavarde_; }
    
    /**
     * @brief Grąžina studento pažymius.
     */
    const vector<int>& getPazymiai() const { return pazymiai_; }
    
    /**
     * @brief Grąžina studento egzamino rezultatą.
     */
    int getEgzaminoRezultatas() const { return egzamino_rezultatas_; }
    
    /**
     * @brief Grąžina studento galutinį vidurkį.
     */
    double getGalutinisVid() const { return galutinis_vid_; }
    
    /**
     * @brief Grąžina studento medianą.
     */
    double getMediana() const { return mediana_; }

    /**
     * @brief Prideda naują pažymį studentui.
     * @param pazymys Naujas pažymys
     */
    void addPazymys(int pazymys) { pazymiai_.push_back(pazymys); }


    /**
     * @brief Skaito studento duomenis.
     * @param is Įvesties srautas
     * @param studentas Studento objektas, į kurį bus įrašyti duomenys
     * @return Įvesties srautas
     */

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

    /**
     * @brief Spausdina studento duomenis.
     * @param os Išvesties srautas
     * @param studentas Studento objektas, kurio duomenys bus išspausdinti
     * @return Išvesties srautas
     */

    friend ostream& operator<<(ostream& os, const Studentas& studentas) {
        os << "Studento informacija:" << endl;
        os << "Vardas: " << studentas.vardas_ << endl;
        os << "Pavarde: " << studentas.pavarde_ << endl;
        os << "Galutinis vidurkis: " << studentas.galutinis_vid_ << endl;
        return os;
    }

    };

#endif