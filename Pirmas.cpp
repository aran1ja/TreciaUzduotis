#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int s, nd;
double vidurkis, galutinis;

struct Duomenys {
    string vardas;
    string pavarde;
    int tarpiniai_rezultatai;
    int egzamino_rezultatas;
};

int main() {

    cout << "Kiek yra studentu? "; cin >> s;
    cout << "Kiek namu darbu buvo uzduota? "; cin >> nd;

    Duomenys *studentas = new Duomenys[s];

    for (int i = 0; i < s; i++) {

        cout << "Iveskite " << i+1 << " studento varda: "; cin >> studentas[i].vardas;
        cout << "Iveskite " << i+1 << " studento pavarde: "; cin >> studentas[i].pavarde;

        for (int j = 0; j < nd; j++) {

            cout << "Iveskite studento pazymi uz " << j+1 << " namu darba: "; cin >> studentas[j].tarpiniai_rezultatai;
        }

        cout << "Iveskite " << i+1 << " studento egzamino rezultata: "; cin >> studentas[i].egzamino_rezultatas;

        vidurkis = 1.00 * studentas[i].tarpiniai_rezultatai / nd;
        galutinis = 0.4 * vidurkis + 0.6 * studentas[i].egzamino_rezultatas;
        cout << "Vidurkis = " << vidurkis << endl; //Blogai skaiciuoja vidurki, del to kencia galutinis rezultatas
        cout << "Galutinis (Vid.) = " << fixed << setprecision(2) << galutinis << endl;
        //Padaryti taip, kad pazymis <= 10, bet >0 arba >=1

        cout << "---------------------------------------" << endl;
    }
}