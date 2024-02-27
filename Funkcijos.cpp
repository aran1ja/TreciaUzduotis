#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>

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

int Studentai() {

    string ivestis_studentai;
    int m;

    cout << "Kiek yra studentu? "; cin >> ivestis_studentai;

    while (true) {

        istringstream iss(ivestis_studentai);

        if (iss >> m) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik studentu skaiciu. ";
                cin >> ivestis_studentai;
            } else {
                if (m <= 0) {
                    cout << "Klaida. Bandykite ivesti kita kieki. ";
                    cin >> ivestis_studentai;
                } else {
                  return m;  
                }
            }
        } else {
            cout << "Klaida. Iveskite studentu skaiciu. ";
            cin >> ivestis_studentai;
        }
    }
}

int NamuDarbai() {

    string ivestis_namu_darbai;
    int n;

    cin >> ivestis_namu_darbai;

    while (true) {

        istringstream iss(ivestis_namu_darbai);

        if (iss >> n) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik namu darbu skaiciu. ";
                cin >> ivestis_namu_darbai;
            } else {
                if (n < 0) {  
                    cout << "Klaida. Bandykite ivesti kita kieki. ";
                    cin >> ivestis_namu_darbai;
                } else {
                    return n;
                }
            }
        } else {
            cout << "Klaida. Iveskite namu darbu skaiciu. ";
            cin >> ivestis_namu_darbai;
        }
    }
}

int Pazymiai() {

    string ivestis_pazymiai;
    int pazymiai;

    cin >> ivestis_pazymiai;

    while (true) {

        istringstream iss(ivestis_pazymiai);

        if (iss >> pazymiai) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite pazymi tik skaiciaus pavidalu. ";
                cin >> ivestis_pazymiai;
            } else {
                return pazymiai;
            }
        } else {
            cout << "Klaida. Iveskite pazymi skaiciaus pavidalu. ";
            cin >> ivestis_pazymiai;
        }
    }
}

int EgzaminoRezultatas() {

    string ivestis_egzamino_rezultatas;
    int rezultatas;

    cin >> ivestis_egzamino_rezultatas;

    while (true) {

        istringstream iss(ivestis_egzamino_rezultatas);

        if (iss >> rezultatas) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite egzamino rezultata tik skaiciaus pavidalu. ";
                cin >> ivestis_egzamino_rezultatas;
            } else {
                return rezultatas;
            }
        } else {
            cout << "Klaida. Iveskite egzamino rezultata skaiciaus pavidalu. ";
            cin >> ivestis_egzamino_rezultatas;
        }
    }
}

int Pasirinkimas1() {

    string pasirinkti_atsakyma1;
    int pasirinkimas1;

    cin >> pasirinkti_atsakyma1;

    while (true) {

        istringstream iss(pasirinkti_atsakyma1);

        if (iss >> pasirinkimas1) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik skaiciu (1, 2 arba 3). ";
                cin >> pasirinkti_atsakyma1;
            } else {
                    return pasirinkimas1;
                }
        } else {
            cout << "Klaida. Iveskite skaiciu (1, 2 arba 3). ";
            cin >> pasirinkti_atsakyma1;
        }
    }
}

int Pasirinkimas2() {

    string pasirinkti_atsakyma2;
    int pasirinkimas2;

    cin >> pasirinkti_atsakyma2;

    while (true) {

        istringstream iss(pasirinkti_atsakyma2);

        if (iss >> pasirinkimas2) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Pasirinkite viena is nurodytu variantu. ";
                cin >> pasirinkti_atsakyma2;
            } else {
                    return pasirinkimas2;
                }
        } else {
            cout << "Klaida. Pasirinkite viena is nurodytu variantu. ";
            cin >> pasirinkti_atsakyma2;
        }
    }
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

int VariantasNamuDarbas() {

    string ivestis_variantas_nd;
    int variantas_namu_darbas;

    cin >> ivestis_variantas_nd;

    while (true) {

        istringstream iss(ivestis_variantas_nd);

        if (iss >> variantas_namu_darbas) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite pazymi tik skaiciaus pavidalu. ";
                cin >> ivestis_variantas_nd;
            } else {
                return variantas_namu_darbas;
            }
        } else {
            cout << "Klaida. Iveskite pazymi skaiciaus pavidalu. ";
            cin >> ivestis_variantas_nd;
        }
    }

}

int VariantasStudentas() {

    string ivestis_variantas_studentas;
    int variantas_studentas;

    cin >> ivestis_variantas_studentas;

    while (true) {

        istringstream iss(ivestis_variantas_studentas);

        if (iss >> variantas_studentas) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite pazymi tik skaiciaus pavidalu. ";
                cin >> ivestis_variantas_studentas;
            } else {
                return variantas_studentas;
            }
        } else {
            cout << "Klaida. Iveskite pazymi skaiciaus pavidalu. ";
            cin >> ivestis_variantas_studentas;
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
 