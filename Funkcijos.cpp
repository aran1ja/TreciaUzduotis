#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>

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

int Pasirinkimas3() {

    string pasirinkti_atsakyma3;
    int pasirinkimas3;

    cin >> pasirinkti_atsakyma3;

    while (true) {

        istringstream iss(pasirinkti_atsakyma3);

        if (iss >> pasirinkimas3) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik viena is nuorodytu skaiciu. ";
                cin >> pasirinkti_atsakyma3;
            } else {
                    return pasirinkimas3;
                }
        } else {
            cout << "Klaida. Iveskite viena is nuorodytu skaiciu. ";
            cin >> pasirinkti_atsakyma3;
        }
    }
}

int Menu() {

    string ivestis_menu;
    int menu;

    cin >> ivestis_menu;

    while (true) {

        istringstream iss(ivestis_menu);

        if (iss >> menu) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite pazymi tik skaiciaus pavidalu. ";
                cin >> ivestis_menu;
            } else {
                return menu;
            }
        } else {
            cout << "Klaida. Iveskite pazymi skaiciaus pavidalu. ";
            cin >> ivestis_menu;
        }
    }
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

    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    file << setw(16) << left << "Vardas" << setw(17) << left << "Pavarde";

    for (int i = 1; i <= ndSkaicius; i++) {
        file << setw(5) << left << "ND" + to_string(i);
    }

    file << setw(5) << left << "Egz." << endl;

    // Generuojami irasai
    for (int i = 0; i <= studentuSkaicius; i++) {
        file << "Vardas" << setw(10) << left << i + 1 << "Pavarde" << setw(10) << left << i + 1;

        // Generuojamas atsitiktiniai namu darbu pazymiai
        for (int j = 0; j < ndSkaicius; j++) {
                file << setw(5) << rand() % 10 + 1;
        }

        // Egzamino rezultatas
        file << setw(5) << rand() % 11 << endl;
    }

    file.close();
}
 