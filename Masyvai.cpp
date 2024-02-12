#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream> // istringstream funkcijai

using namespace std;

int m, n, variantas_namu_darbas, variantas_studentas, pasirinkimas; // m - studentu skaicius, n - namu darbu skaicius
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
    
    int m = 0;
    
    Studentas *studentas = nullptr;

    int variantas_studentas = 1;

    while (variantas_studentas != 0) {

        m++;

        Studentas* naujas_studentas = new Studentas[m];

        for (int i = 0; i < m -1; i++) {
            naujas_studentas[i] = studentas[i];
        }

        delete[] studentas;

        studentas = naujas_studentas;


        suma = 0.00;

        cout << "Iveskite " << m << " studento varda: "; cin >> studentas[m - 1].vardas;
        cout << "Iveskite " << m << " studento pavarde: "; cin >> studentas[m - 1].pavarde;
        cout << "Iveskite kiek namu darbu pazymiu norite ivesti. ";

        int n = NamuDarbai();

        studentas[m - 1].pazymiai = new int[n];

        for (int j = 0; j < n; j++) {

            /**/

            cout << "Studento pazymis uz " << j+1 << " namu darba: ";
            int pazymiai = Pazymiai();
            studentas[m - 1].pazymiai[j] = pazymiai;

            while (studentas[m - 1].pazymiai[j] > 10 || studentas[m - 1].pazymiai[j] < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento pazymis uz " << j+1 << " namu darba: "; 
                int pazymiai = Pazymiai();
                studentas[m - 1].pazymiai[j] = pazymiai;    
            } 
                //Skaiciuoja suma visu pazymiu 
                suma += studentas[m - 1].pazymiai[j];  
               }
            
            // Ciklas, kuris uzduoda klausima, ar vartotojas nori ivesti dar viena namu darbo rezultata
            do {

                cout << "Ar norite ivesti dar vieno namu darbo pazymi?\nJeigu ne, spauskite 0.\nJeigu taip, spauskite 1. ";
                cin >> variantas_namu_darbas; 

                while (variantas_namu_darbas != 0 && variantas_namu_darbas != 1) {
                    cout << "Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1). ";
                    cin >> variantas_namu_darbas;
                }

                if (variantas_namu_darbas == 1) {
                    n++;

                    cout << "Iveskite pazymi uz " << n << " namu darba: ";
                    int pazymiai = Pazymiai();

                    while (pazymiai > 10 || pazymiai < 1) {
                        cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                        cout << "Studento pazymis uz " << n << " namu darba: "; 
                        int pazymiai = Pazymiai();
                        
                    }
                    studentas[m - 1].pazymiai[n - 1] = pazymiai;
                    suma += studentas[m - 1].pazymiai[n - 1];
                }

            } while (variantas_namu_darbas != 0);

            
            cout << "suma: " << suma << endl;
            
            /**/

            cout << "Studento egzamino rezultatas: "; 
            int rezultatas = EgzaminoRezultatas();
            studentas[m - 1].egzamino_rezultatas = rezultatas;

            while (studentas[m - 1].egzamino_rezultatas > 10 || studentas[m - 1].egzamino_rezultatas < 1) {
                cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                cout << "Studento egzamino rezultatas: ";
                int rezultatas = EgzaminoRezultatas();
                studentas[m - 1].egzamino_rezultatas = rezultatas;
                }


        //Jeigu nebuvo jokiu namu darbu, galutinis vidurkis skaiciuojamas tik is egzamino rezultato
        if (n == 0) {
            vidurkis = 0;
        } else {
            vidurkis = suma / n * 1.00;
        }
        
        //Galutinio vidurkio skaiciavimas
        studentas[m - 1].galutinis_vid = 0.4 * vidurkis + 0.6 * studentas[m - 1].egzamino_rezultatas;

        //Mediana
        int *visi_pazymiai = new int[n + 1];          

            for (int b = 0; b < n; b++) {
                visi_pazymiai[b] = studentas[m - 1].pazymiai[b];
            }
            visi_pazymiai[n] = studentas[m - 1].egzamino_rezultatas;
 
            studentas[m - 1].mediana = mediana(visi_pazymiai, n + 1);

            delete[] visi_pazymiai;
        

        cout << "--------------------------------------------------" << endl;

        cout << "Ar norite prideti dar vieno studento duomenis?" << endl;
        cout << "Jeigu ne, spauskite 0. Jeigu taip, spauskite 1.";
        cin >> variantas_studentas;

        if (variantas_studentas == 0)
            break;
    }

        //Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
        cout << "Ka programa turi atvaizduoti?" << endl;
        cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
        cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
        cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
        int pasirinkimas = Pasirinkimas();

        while (pasirinkimas != 1 || pasirinkimas != 2 || pasirinkimas != 3) {

        if (pasirinkimas == 1) {

            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------" << endl;

             for (int i = 0; i < m; i++) {
                cout << left << setw(15) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(15);
                cout << fixed << setprecision(2) << studentas[i].galutinis_vid << endl;
            } break;

        } else if (pasirinkimas == 2) {

            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------" << endl;

            for (int i = 0; i < m; i++) {
                cout << left << setw(15) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(15);
                cout << fixed << setprecision(2) << studentas[i].mediana << endl;
            } break;

        } else if (pasirinkimas == 3) {

            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (int i = 0; i < m; i++) {
                cout << left << setw(15) << studentas[i].vardas << setw(15) << studentas[i].pavarde << setw(15);
                cout << fixed << setprecision(2) << studentas[i].galutinis_vid << setw(30);
                cout << fixed << setprecision(2) << studentas[i].mediana << endl;
            } break;
        }              

            cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
            cout << "Spauskite 1, 2 arba 3. "; 
            int pasirinkimas = Pasirinkimas(); 
    }

    for (int i = 0; i < m; i++) {
        delete[] studentas[i].pazymiai;
    }
     delete[] studentas;

     return 0;
}