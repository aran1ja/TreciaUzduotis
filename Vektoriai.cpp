#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream> // istringstream funkcijai
#include <cstdlib> // random number generacijai
#include <ctime>
#include <vector>

using namespace std;

int m, n, menu; // m - studentu skaicius, n - namu darbu skaicius
int variantas_namu_darbas, variantas_studentas, pasirinkimas; 
double suma, vidurkis;

struct Studentas {
    string vardas, pavarde;
    double galutinis_vid, mediana;
    vector<int> pazymiai;
    int egzamino_rezultatas;
};

double mediana(vector<int>& arr) {
    sort (arr.begin(), arr.end());
    int kiekis = arr.size();
    if (kiekis % 2 == 0) {
        return (arr[kiekis / 2 - 1] + arr[kiekis / 2]) / 2.0;
    } else {
        return arr[kiekis / 2];
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

int Pasirinkimas() {

    string pasirinkti_atsakyma;
    int pasirinkimas;

    cin >> pasirinkti_atsakyma;

    while (true) {

        istringstream iss(pasirinkti_atsakyma);

        if (iss >> pasirinkimas) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik skaiciu (1, 2 arba 3). ";
                cin >> pasirinkti_atsakyma;
            } else {
                    return pasirinkimas;
                }
        } else {
            cout << "Klaida. Iveskite skaiciu (1, 2 arba 3). ";
            cin >> pasirinkti_atsakyma;
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

// Vardus ir pavardes generuoti
const int ch_MAX = 52;
string RandomString(int ch) {
    char gener[ch_MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 
                          'c', 'd', 'e', 'f', 'g', 'h', 'i', 
                          'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                          'q', 'r', 's', 't', 'u', 'v', 'w', 
                          'x', 'y', 'z'};

        string rezultatas = "";
        for (int i = 0; i < ch; i++)
            rezultatas = rezultatas + gener[rand() % ch_MAX];
        
        return rezultatas;
}