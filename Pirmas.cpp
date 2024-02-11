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
    int *pazymiai, egzamino_rezultatas;
};

double median(int arr[]) {
    sort (arr, arr + nd);
    if (nd % 2 == 0) {
        return (arr[nd / 2 - 1] + arr[nd / 2]) / 2.0;
    } else {
        return arr[nd / 2];
    }
}

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

    for (int i = 0; i < s; i++) {

        suma = 0.00;

        cout << "Iveskite " << i+1 << " studento varda: "; cin >> studentas[i].vardas;
        cout << "Iveskite " << i+1 << " studento pavarde: "; cin >> studentas[i].pavarde;

        studentas[i].pazymiai = new int[nd];

        for (int j = 0; j < nd; j++) {

            cout << "Studento pazymis uz " << j+1 << " namu darba: "; cin >> studentas[i].pazymiai[j];

            while (studentas[i].pazymiai[j] > 10 || studentas[i].pazymiai[j] < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento pazymis uz " << j+1 << " namu darba: "; cin >> studentas[i].pazymiai[j];
            } 
                //Skaiciuoja suma visu pazymiu 
                suma += studentas[i].pazymiai[j];  
               }
            
            cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;

            while (studentas[i].egzamino_rezultatas > 10 || studentas[i].egzamino_rezultatas < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento egzamino rezultatas: "; cin >> studentas[i].egzamino_rezultatas;
                }

        //Mediana
         for (int a = 0; a < s; a++) {
            int *visi_pazymiai = new int[nd + 1];
            for (int b = 0; b < nd; b++) {
                visi_pazymiai[b] = studentas[i].pazymiai[b];
            }
            visi_pazymiai[nd] = studentas[i].egzamino_rezultatas;

            double mediana = median(visi_pazymiai);
            studentas[i].mediana = mediana;

            delete[] visi_pazymiai;
         }
        
        //studentas[i].mediana = 0.5 * (pazymiai[i][(nd - 1) / 2] + pazymiai[i][nd / 2]);
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

        ////cout << "Vidurkis = " << fixed << setprecision(2) << vidurkis << endl;
        cout << "--------------------------------------------------" << endl;
    }

        //Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
        cout << "Ka programa turi atvaizduoti?" << endl;
        cout << "Jeigu reikalingas vidurkis, spauskite 1.\nJeigu reikalinga mediana, spauskite 2." << endl;
        cin >> pasirinkimas;

        while (pasirinkimas != 1 || pasirinkimas != 2) {

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
                cout << fixed << setprecision(2) << studentas[i].mediana << endl;
            } break;
        }

            cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
            cout << "Spauskite 1 arba 2. "; cin >> pasirinkimas;
    }

    for (int i = 0; i < s; i++) {
        delete[] studentas[i].pazymiai;
    }
     delete[] studentas;

     return 0;
}