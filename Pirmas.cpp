#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cctype> // isdigit funkcijai
#include <sstream> // istringstream funkcijai

using namespace std;

int s, nd, pasirinkimas;
double suma, vidurkis;

struct Studentas {
    string vardas, pavarde;
    double galutinis_vid, mediana;
    int *pazymiai, egzamino_rezultatas;
};

double mediana(int arr[], int kiekis) {
    sort (arr, arr + kiekis);
    if (kiekis % 2 == 0) {
        return (arr[kiekis / 2 - 1] + arr[kiekis / 2]) / 2.0;
    } else {
        return arr[kiekis / 2];
    }
}

int Studentai() {

    string ivestis_studentai;
    int s;

    cout << "Kiek yra studentu? "; cin >> ivestis_studentai;

    while (true) {

        istringstream iss(ivestis_studentai);

        if (iss >> s) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik studentu skaiciu. ";
                cin >> ivestis_studentai;
            } else {
                if (s <= 0) {
                    cout << "Klaida. Bandykite ivesti kita kieki. ";
                    cin >> ivestis_studentai;
                } else {
                  return s;  
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
    int nd;

    cout << "Kiek namu darbu buvo uzduota? "; cin >> ivestis_namu_darbai;

    while (true) {

        istringstream iss(ivestis_namu_darbai);

        if (iss >> nd) {
            char remaining;
            if (iss >> remaining) {
                cout << "Klaida. Iveskite tik namu darbu skaiciu. ";
                cin >> ivestis_namu_darbai;
            } else {
                if (nd < 0) {  
                    cout << "Klaida. Bandykite ivesti kita kieki. ";
                    cin >> ivestis_namu_darbai;
                } else {
                    return nd;
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

int main() {

    /* 
    Ivedama kiek yra studentu. Ju gali buti tik naturalusis skaicius.
    Jeigu ivedama raide, atsiranda zinute "Klaida. Iveskite studentu skaiciu."
    Jeigu ivedamas skaicius su raide, atsiranda zinute "Klaida. Iveskite tik studentu skaiciu."
    */ 
    
    int s = Studentai();

    /* 
    Ivedama kiek yra namu darbu. Ju gali buti 0 ir daugiau.
    Jeigu ivedama raide, atsiranda zinute "Klaida. Iveskite namu darbu skaiciu."
    Jeigu ivedamas skaicius su raide, atsiranda zinute "Klaida. Iveskite tik namu darbu skaiciu."
    */

    int nd = NamuDarbai();
        
    Studentas *studentas = new Studentas[s];

    for (int i = 0; i < s; i++) {

        suma = 0.00;

        cout << "Iveskite " << i+1 << " studento varda: "; cin >> studentas[i].vardas;
        cout << "Iveskite " << i+1 << " studento pavarde: "; cin >> studentas[i].pavarde;

        studentas[i].pazymiai = new int[nd];

        for (int j = 0; j < nd; j++) {

            /*
            Ivedami studento pazymiai pagal 10 bale sistema. Jie gali buti nuo 1 iki 10.
            Jeigu ivedama raide, atsiranda zinute "Klaida. Iveskite pazymi tik skaiciaus pavidalu."
            Jeigu ivedamas skaicius su raide, atsiranda zinute "Klaida. Iveskite pazymi skaiciaus pavidalu."
            */

            string ivestis_pazymiai;
            cout << "Studento pazymis uz " << j+1 << " namu darba: ";
            int pazymiai = Pazymiai();
            studentas[i].pazymiai[j] = pazymiai;

            while (studentas[i].pazymiai[j] > 10 || studentas[i].pazymiai[j] < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento pazymis uz " << j+1 << " namu darba: "; 
                int pazymiai = Pazymiai();
                studentas[i].pazymiai[j] = pazymiai;    
            } 
                //Skaiciuoja suma visu pazymiu 
                suma += studentas[i].pazymiai[j];  
               }
            
            /*
            Ivedamas studento egzamino rezultatas pagal 10 bale sistema. Jis gali buti nuo 1 iki 10.
            Jeigu ivedama raide, atsiranda zinute "Klaida. Iveskite egzamino rezultata tik skaiciaus pavidalu."
            Jeigu ivedamas skaicius su raide, atsiranda zinute "Klaida. Iveskite egzamino rezultata skaiciaus pavidalu."
            */

            string ivestis_egzamino_rezultatas;
            cout << "Studento egzamino rezultatas: "; 
            int rezultatas = EgzaminoRezultatas();
            studentas[i].egzamino_rezultatas = rezultatas;

            while (studentas[i].egzamino_rezultatas > 10 || studentas[i].egzamino_rezultatas < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento egzamino rezultatas: ";
                int rezultatas = EgzaminoRezultatas();
                studentas[i].egzamino_rezultatas = rezultatas;
                }

        //Jeigu nebuvo jokiu namu darbu, galutinis vidurkis skaiciuojamas tik is egzamino rezultato
        if (nd == 0) {
            vidurkis = 0;
        } else {
            vidurkis = suma / nd * 1.00;
        }
        
        //Galutinio vidurkio skaiciavimas
        studentas[i].galutinis_vid = 0.4 * vidurkis + 0.6 * studentas[i].egzamino_rezultatas;

        //Mediana
         for (int a = 0; a < s; a++) {

            int *visi_pazymiai = new int[nd + 1];

            for (int b = 0; b < nd; b++) {
                visi_pazymiai[b] = studentas[i].pazymiai[b];
            }
            visi_pazymiai[nd] = studentas[i].egzamino_rezultatas;
 
            studentas[i].mediana = mediana(visi_pazymiai, nd + 1);

            delete[] visi_pazymiai;
            }

        cout << "--------------------------------------------------" << endl;
    }

        //Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
        cout << "Ka programa turi atvaizduoti?" << endl;
        cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
        cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
        cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
        int pasirinkimas = Pasirinkimas();

        while (pasirinkimas != 1 || pasirinkimas != 2 || pasirinkimas != 3) {

            cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
            cout << "Spauskite 1, 2 arba 3. "; 
            int pasirinkimas = Pasirinkimas(); 

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

        } else if (pasirinkimas == 3) {

            cout << "Vardas\t Pavarde\t Galutinis (Vid.) Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < s; i++) {
                cout << studentas[i].vardas << "\t " << studentas[i].pavarde << "\t ";
                cout << fixed << setprecision(2) << studentas[i].galutinis_vid << "\t ";
                cout << fixed << setprecision(2) << studentas[i].mediana << endl;
            } break;
        } 

                   
    }

    for (int i = 0; i < s; i++) {
        delete[] studentas[i].pazymiai;
    }
     delete[] studentas;

     return 0;
}