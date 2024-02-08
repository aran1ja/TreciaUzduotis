#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int s, nd;
double suma, vidurkis, galutinis_vid, mediana;

struct Duomenys {
    string vardas;
    string pavarde;
    int pazymiai;
    int egzamino_rezultatas;
};

int main() {

    cout << "Kiek yra studentu? "; cin >> s;
    cout << "Kiek namu darbu buvo uzduota? "; cin >> nd;

    Duomenys *studentas = new Duomenys[s];
    int **pazymiai = new int*[s];

    for (int i = 0; i < s; i++) {

        suma = 0.00;

        cout << "Iveskite " << i+1 << " studento varda: "; cin >> studentas[i].vardas;
        cout << "Iveskite " << i+1 << " studento pavarde: "; cin >> studentas[i].pavarde;

        pazymiai[i] = new int[nd];

        for (int j = 0; j < nd; j++) {

            cout << "Studento pazymis uz " << j+1 << " namu darba: "; cin >> pazymiai[i][j];

            while (pazymiai[i][j] > 10 || pazymiai[i][j] < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento pazymis uz " << j+1 << " namu darba: "; cin >> pazymiai[i][j];
            } 
               suma += pazymiai[i][j]; //Skaiciuoja suma visu pazymiu  
               mediana = 0.5 * (pazymiai[i][(nd - 1) / 2] + pazymiai[i][nd / 2]); //Ne visada gerai skaiciuoja rezultata
               }
            
            
            cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;

            while (studentas[i].egzamino_rezultatas > 10 || studentas[i].egzamino_rezultatas < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;
                }

        vidurkis = suma / nd * 1.00;
        galutinis_vid = 0.4 * vidurkis + 0.6 * studentas[i].egzamino_rezultatas;
        cout << "Vidurkis = " << fixed << setprecision(2) << vidurkis << endl; 
        cout << "Galutinis (Vid.) = " << fixed << setprecision(2) << galutinis_vid << endl;
        cout << "Galutinis (Med.) = " << fixed << setprecision(2) << mediana << endl; 

        cout << "---------------------------------------" << endl;
    }
}