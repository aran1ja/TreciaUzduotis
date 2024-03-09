#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>

// Mediana
double mediana(vector<int> pazymiai, int egzamino_rezultatas) {
    pazymiai.push_back(egzamino_rezultatas);
    size_t kiekis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());

    if (kiekis % 2 == 0) {
        return (pazymiai[kiekis / 2 - 1] + pazymiai[kiekis / 2]) / 2.0;
    } else {
        return pazymiai[kiekis / 2];
    }
}

// Vidurkis
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas) {
    if (n == 0) {
        return 0.6 * egzamino_rezultatas;
    } else {
        return 0.4 * (suma / n) + 0.6 * egzamino_rezultatas;
    }
}

// Rusiuojama pagal varda (didejimo tvarka)
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b) {
    return a.vardas < b.vardas;
}

// Rusiuojama pagal pavarde (didejimo tvarka)
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b) {
    return a.pavarde < b.pavarde;
}

// Rusiuojama pagal mediana (mazejimo tvarka)
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b) {
    return a.mediana > b.mediana;
}

// Rusiuojama pagal galutini vidurki (mazejimo tvarka)
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b) {
    return a.galutinis_vid > b.galutinis_vid;
}

double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0.0;
    for (int pazymys : pazymiai) {
        suma += pazymys;
    }
    return suma / pazymiai.size();
}

void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1) {

        switch (pasirinkimas1) {
            case 1:
                cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.)" << endl;
                cout << "--------------------------------------------------" << endl;

                for (const auto& studentas : studentai) {
                    cout << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                    cout << fixed << setprecision(2) << studentas.galutinis_vid << endl;
                }
                break;
            case 2:
                cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Med.)" << endl;
                cout << "--------------------------------------------------" << endl;

                for (const auto& studentas : studentai) {
                    cout << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                    cout << fixed << setprecision(2) << studentas.mediana << endl;
                }
                break;
            case 3:
                cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
                cout << "-----------------------------------------------------------------" << endl;

                for (const auto& studentas : studentai) {
                    cout << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                    cout << fixed << setprecision(2) << studentas.galutinis_vid << setw(30);
                    cout << fixed << setprecision(2) << studentas.mediana << endl;
                }
                break;
        } 
}

void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius) {
    ofstream file(failoPavadinimas);
    //stringsream

    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    auto pradzios_laikas = chrono::steady_clock::now();

    file << setw(16) << left << "Vardas" << setw(17) << left << "Pavarde";

    for (int i = 1; i <= ndSkaicius; i++) {
        file << setw(5) << left << "ND" + to_string(i);
    }

    file << setw(5) << left << "Egz." << endl;

    // Generuojami irasai
    for (int i = 0; i < studentuSkaicius; i++) {
        file << "Vardas" << setw(10) << left << i + 1 << "Pavarde" << setw(10) << left << i + 1;

        // Generuojamas atsitiktiniai namu darbu pazymiai
        for (int j = 0; j < ndSkaicius; j++) {
                file << setw(5) << rand() % 10 + 1;
        }

        // Egzamino rezultatas
        file << setw(5) << rand() % 11 << endl;
    }

    file.close();

    auto pabaigos_laikas = chrono::steady_clock::now();
    auto laiko_skirtumas = chrono::duration <double> (pabaigos_laikas - pradzios_laikas).count();
    cout << "Failo kurimo ir uzdarymo laikas: " << fixed << setprecision(4) << laiko_skirtumas << "s" << endl;
}

void failoIsvedimas(const vector<Studentas>& studentai, string failoPavadinimas) {
    ofstream file(failoPavadinimas);
    
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    file << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    file << "--------------------------------------------------------" << endl;
    for (const auto& studentas : studentai) {
        file << setw(15) << left << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << fixed << setprecision(2) << studentas.galutinis_vid << endl;
    }

    file.close();
}

void nuskaitytiFaila(string failoPavadinimas, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
    ifstream fileName(failoPavadinimas);
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double nuskaitymoLaikas = 0.0;

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

        stringstream ss(eilute);
        Studentas naujas_studentas;
        int pazymiai, skaicius_pazymiu = 0;
        ss >> naujas_studentas.vardas >> naujas_studentas.pavarde;

        while(ss >> pazymiai){
            if(!ss.eof()){
                        
            // Namu darbu pazymiai
            naujas_studentas.pazymiai.push_back(pazymiai);
            skaicius_pazymiu++; 
            } else {

            // Egzamino rezultatas
            naujas_studentas.egzamino_rezultatas = pazymiai;
            }
        }

        double pazymiu_suma = 0.0;
            for (int pazymiai : naujas_studentas.pazymiai) {
                pazymiu_suma += pazymiai;
            }

        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * skaicius_pazymiu / skaicius_pazymiu) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

    }

        cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
        
    fileName.close();
}

void studentuRusiavimas(vector<Studentas>& naujas_studentas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
    double visasLaikas = 0.0;

    // Padaromi 2 nauji konteineriai
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;

    auto pradedam = chrono::steady_clock::now();

    // Studento pridėjimas į atitinkamą konteinerį i rūšiavimas
    for (const auto& studentas : naujas_studentas) {
        if (studentas.galutinis_vid < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }

    // Sortowanie studentów
    sort(vargsiukai.begin(), vargsiukai.end(), [](const Studentas& a, const Studentas& b) {
        return (0.4 * skaiciuotiVidurki(a.pazymiai) + 0.6 * a.egzamino_rezultatas) < (0.4 * skaiciuotiVidurki(b.pazymiai) + 0.6 * b.egzamino_rezultatas); });

    sort(kietiakai.begin(), kietiakai.end(), [](const Studentas& a, const Studentas& b) {
        return (0.4 * skaiciuotiVidurki(a.pazymiai) + 0.6 * a.egzamino_rezultatas) < (0.4 * skaiciuotiVidurki(b.pazymiai) + 0.6 * b.egzamino_rezultatas); });

    auto pabaigiam = chrono::steady_clock::now();
    auto skaiciuojam = chrono::duration<double>(pabaigiam - pradedam).count();
    visasLaikas += skaiciuojam;

    cout << "Studentų rūšiavimo į dvi grupes laikas: " << fixed << setprecision(4) << visasLaikas << "s" << endl;

    auto laikas1 = chrono::steady_clock::now();

    // Issaugome vargsiukus ir kietakius atskiruose failuose
    failoIsvedimas(vargsiukai, vargsiukuFailoPavadinimas);
    failoIsvedimas(kietiakai, kietakiuFailoPavadinimas);

    auto laikas2 = chrono::steady_clock::now();
    auto laiku1_2_skirtumas = chrono::duration<double>(laikas2 - laikas1).count();
    cout << "Surūšiuotų studentų išvedimo į naujus failus laikas: " << fixed << setprecision(4) << laiku1_2_skirtumas << "s" << endl;
}
