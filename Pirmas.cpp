#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>

using namespace std;

int s, nd;

struct duomenys {
    string vardas;
    string pavarde;
    int tarpiniai_rezultatai;
    int egzamino_rezultatas;
};

int main() {

    duomenys d;

    cout << "Kiek yra studentu? ";
    cin >> s;
    cout << "Kiek namu darbu buvo uzduota? ";
    cin >> nd;

    for (int i = 1; i <= s; i++) {

        cout << "Iveskite " << i << " studento varda: ";
        cin >> d.vardas;
        cout << "Iveskite " << i << " studento pavarde: ";
        cin >> d.pavarde;

        for (int j = 1; j <= nd; j++) {

            cout << "Iveskite studento pazymi uz " << j << " namu darba: ";
            cin >> d.tarpiniai_rezultatai;
        }

        cout << "Iveskite " << i << " studento egzamino rezultata: ";
        cin >> d.egzamino_rezultatas;

        cout << "---------------------------------------" << endl;
    }
}