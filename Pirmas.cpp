#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int s, nd, pasirinkimas;
double suma, vidurkis;

struct Studentas {
    string vardas, pavarde;
    double galutinis_vid, mediana;
    int pazymiai, egzamino_rezultatas;
};

int main() {

    cout << "Kiek yra studentu? "; cin >> s;
    while (s <= 0) {
        cout << "Klaida. Bandykite ivesti kita kieki. "; cin >> s;
    }

    cout << "Kiek namu darbu buvo uzduota? "; cin >> nd;
    while (nd < 0) {
        cout << "Klaida. Bandykite ivesti kita kieki. "; cin >> nd;
    }
        
    Studentas *studentas = new Studentas[s];
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
               }
            
            cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;

            while (studentas[i].egzamino_rezultatas > 10 || studentas[i].egzamino_rezultatas < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;
                }

        //Mediana
        studentas[i].mediana = 0.5 * (pazymiai[i][(nd - 1) / 2] + pazymiai[i][nd / 2]);
        //Liczy mediane tylko z ocen, NIE z egzaminu wlacznie
        //Liczy tylko podany srodek - NIE MA sortowania cyfr od najmniejszej do najwiekszej

        //Jeigu nebuvo jokiu namu darbu, galutinis vidurkis skaiciuojamas tik is egzamino rezultato
        if (nd == 0) {
            vidurkis = 0;
        } else {
            vidurkis = suma / nd * 1.00;
        }
        
        //Galutinio vidurkio skaiciavimas
        studentas[i].galutinis_vid = 0.4 * vidurkis + 0.6 * studentas[i].egzamino_rezultatas;
        cout << "Vidurkis = " << fixed << setprecision(2) << vidurkis << endl; 
        cout << "--------------------------------------------------" << endl;
    }

        //Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
        cout << "Ka programa turi atvaizduoti?" << endl;
        cout << "Jeigu reikalingas vidurkis, spauskite 1.\nJeigu reikalinga mediana, spauskite 2." << endl;
        cin >> pasirinkimas;


        while (pasirinkimas != 1 || pasirinkimas != 2) {

            cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
            cout << "Spauskite 1 arba 2. "; cin >> pasirinkimas;

            if (pasirinkimas == 1) {

            cout << "Vardas\t Pavarde\t Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;

             for (int i = 0; i < s; i++) {
                 cout << studentas[i].vardas << "\t " << studentas[i].pavarde << "\t ";
                cout << fixed << setprecision(2) << studentas[i].galutinis_vid << endl;
            } break;

        } else if (pasirinkimas == 2) {

            cout << "Vardas\t Pavarde\t Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < s; i++) {
                 cout << studentas[i].vardas << "\t " << studentas[i].pavarde << "\t ";
                cout << "Cia turi buti mediana" << endl;
            } break;
        }
    }
}