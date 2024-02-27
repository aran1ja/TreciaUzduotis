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
#include <fstream>
#include <chrono>  //Laiko matavimui
#include "studentas.h"
#include "funkcijos.h"

using namespace std;

int m, n, menu; // m - studentu skaicius, n - namu darbu skaicius
int variantas_namu_darbas, variantas_studentas, pasirinkimas; 
double suma, vidurkis;
int MAX_ND = 30;
int MAX_STUDENTU = 30;

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
                
int main() {

    vector <Studentas> A;

    while (true) {

        // Menu
        cout << "Isrinkite programos eigos buda paspaudus nurodyta skaiciu." << endl;
        cout << "1. Visi duomenys ivedami ranka. " << endl;
        cout << "2. Studento duomenys ivedami ranka, o pazymiai generuojami programos. " << endl;
        cout << "3. Visa informacija yra programos generuojama." << endl;
        cout << "4. Nuskaityti duomenis is failo. " << endl;
        cout << "5. Baigti darba." << endl;
        cout << "Jusu pasirinkimas: "; 
        int menu = Menu();

        switch (menu) {

            // Menu 1
            case 1:
            {
                
            vector<Studentas> studentai;

            int m = 0;
            int variantas_studentas = 1;

            // Pridedami studentai
            while (variantas_studentas != 0) {
                m++;

                Studentas naujas_studentas;

                cout << "Irasykite " << m << " studento varda: "; cin >> naujas_studentas.vardas;
                cout << "Irasykite " << m << " studento pavarde: "; cin >> naujas_studentas.pavarde;

                cout << "Iveskite kiek namu darbu pazymiu norite ivesti. ";
                int n = NamuDarbai();

                for (int j = 0; j < n; j++) {
                int pazymiai;

                    do {
                        cout << "Studento pazymis uz " << j + 1 << " namu darba: ";
                        pazymiai = Pazymiai();

                        if (pazymiai > 10 || pazymiai < 1) {
                            cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                        }
                    } while (pazymiai > 10 || pazymiai < 1);

                    naujas_studentas.pazymiai.push_back(pazymiai);
                } 

                do {

                    cout << "Ar norite ivesti dar vieno namu darbo pazymi?\nJeigu ne, spauskite 0.\nJeigu taip, spauskite 1. ";
                    variantas_studentas = VariantasNamuDarbas(); 

                    while (variantas_studentas != 0 && variantas_studentas != 1) {
                        cout << "Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1). ";
                        variantas_studentas = VariantasNamuDarbas();
                    }

                    if (variantas_studentas == 1) {
                        n++;
                        int pazymiai;

                        
                        cout << "Studento pazymis uz " << n << " namu darba: ";
                        pazymiai = Pazymiai();

                        if (pazymiai > 10 || pazymiai < 1) {
                            cout << "Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10." << endl;
                            cout << "Studento pazymis uz " << n << " namu darba: ";
                            pazymiai = Pazymiai();
                        }

                            naujas_studentas.pazymiai.push_back(pazymiai); // Pazymis pridedamas prie pazymiu vektoriu

                            suma += pazymiai;
                        }

                        naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                        naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);
                    
                    
                    } while (variantas_studentas != 0);

                cout << "Studento egzamino rezultatas: ";
                int rezultatas = EgzaminoRezultatas();
                naujas_studentas.egzamino_rezultatas = rezultatas;

                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio skaiciavimas
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);

                // Mediana
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);

                cout << "--------------------------------------------------" << endl;
                cout << "Ar norite prideti dar vieno studento duomenis?" << endl;
                cout << "Jeigu ne, spauskite 0. Jeigu taip, spauskite bet koki kita skaiciu. ";
                variantas_studentas = VariantasStudentas();

                if (variantas_studentas == 0)
                    break;
                }

                //Pasirinkimas
                // Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas = Pasirinkimas();

            while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
                cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
                cout << "Spauskite 1, 2 arba 3. ";
                pasirinkimas = Pasirinkimas();
            }

        // Atvaizdavimas pagal vartotojo pasirinkima
        switch (pasirinkimas) {
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
         break;

            } 

            // Menu 2
            case 2:
            {

            srand(time(NULL));

            vector<Studentas> studentai;
            int m = Studentai();
            int n = rand() % (MAX_ND + 1);
            
            for (int i = 0; i < m; i++) {

                Studentas naujas_studentas;                
                cout << "Irasykite " << i + 1 << " studento varda: "; cin >> naujas_studentas.vardas;
                cout << "Irasykite " << i + 1 << " studento pavarde: "; cin >> naujas_studentas.pavarde;

                for (int j = 0; j < n; j++) {
            
                    int pazymiai = (rand() % 10) + 1;
                    naujas_studentas.pazymiai.push_back(pazymiai);
                }

                naujas_studentas.egzamino_rezultatas = rand() % 10 + 1;
            
                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio skaiciavimas
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);

                // Mediana
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);
            
            }

                //Pasirinkimas
                // Vartotojas pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas = Pasirinkimas();

            while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
                cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
                cout << "Spauskite 1, 2 arba 3. ";
                pasirinkimas = Pasirinkimas();
            }

        // Atvaizdavimas pagal vartotojo pasirinkima
        switch (pasirinkimas) {
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
         break;

            }

            // Menu 3
            case 3:
            {

            srand(time(NULL));

            vector<string> vardai = {"Adriana", "Emil", "Milana", "Diana", "Andrej", "Marta", "Paulius", "Edita", "Gabriele", "Dominikas"};
            vector<string> pavardes = {"Sirokyte", "Voisvilo", "Demesko", "Pipilevic", "Machnicka", "Voitkevic", "Podgaiska", "Sakson", "Juneviciute", "Petkeviciene"};

            vector<Studentas> studentai;
            int m = rand() % (MAX_STUDENTU + 1);
            

            for (int i = 0; i < m; i++) {

                Studentas naujas_studentas;   
                naujas_studentas.vardas = vardai[rand() % vardai.size()];             
                naujas_studentas.pavarde = pavardes[rand() % vardai.size()];
                int n = rand() % (MAX_ND + 1);

                for (int j = 0; j < n; j++) {
            
                    int pazymiai = (rand() % 10) + 1;
                    naujas_studentas.pazymiai.push_back(pazymiai);
                }

                naujas_studentas.egzamino_rezultatas = rand() % 11;
            
                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio skaiciavimas
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);

                // Mediana
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);
            
            }

                //Pasirinkimas
                // Vartotojas pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas = Pasirinkimas();

            while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
                cout << "Klaida. Bandykite ivesti reikiama skaiciu dar karta." << endl;
                cout << "Spauskite 1, 2 arba 3. ";
                pasirinkimas = Pasirinkimas();
            }

        // Atvaizdavimas pagal vartotojo pasirinkima
        switch (pasirinkimas) {
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
         break;

            }

            // Menu 4
            case 4: 
            {
            int skaicius = 0;
            string smth;
            string failas;                
            vector<double> laikai;
            int pasirinkimas2 = 0;

            do {

            cout << "Koki faila programa turi nuskaityti?" << endl;
            cout << "1. studentai10000.txt" << endl;
            cout << "2. studentai100000.txt" << endl;
            cout << "3. studentai1000000.txt" << endl;
            cout << "4. kursiokai.txt" << endl;
            cout << "0. Pabaigti." << endl;
            cout << "Jusu pasirinkimas: "; 
            pasirinkimas2 = Pasirinkimas2();

            if(pasirinkimas2 == 1) {
                failas = "studentai10000.txt";
            }

            if(pasirinkimas2 == 2) {
                failas = "studentai100000.txt";
            }

            if(pasirinkimas2 == 3) {
                failas = "studentai1000000.txt";
            }

            if(pasirinkimas2 == 4) {
                failas = "kursiokai.txt";
            }

            if(pasirinkimas2 == 0) {
                break;
            }

            vector<Studentas> studentai;
            ifstream fileName(failas);
            string eilute;

            // Exception handling
            try {
                if (!fileName.is_open()) 
                throw runtime_error("Nepavyko atidaryti failo. Bandykite dar karta.");
            
            } catch (const runtime_error& klaida) {
                cout << klaida.what() << endl;
                break;
            }

            auto start = chrono::steady_clock::now();

            while (smth != "Egz.") {
                fileName >> smth;

                skaicius++;
            }

            skaicius = skaicius - 3;

                // Neskaitoma pirma eilute is failo
                getline(fileName, eilute);

                while (getline(fileName, eilute)) {
                    stringstream ss(eilute);
                    Studentas naujas_studentas;
                    int pazymiai, suma = 0;
                    ss >> naujas_studentas.vardas >> naujas_studentas.pavarde;

                    for (int i = 0; i < skaicius; i++) {
                        ss >> pazymiai;
                        naujas_studentas.pazymiai.push_back(pazymiai);
                        suma += pazymiai;
                    }

                    // Egzamino rezultatas
                    ss >> naujas_studentas.egzamino_rezultatas;

                    // Galutinio vidurkio ir medianos skaiciavimai
                    naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;
                    naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                    // Pridedamas studentas
                    studentai.push_back(naujas_studentas);
                }

                fileName.close();

                // Pasirenkame pagal kokia kriterija ruosiosime
                int pasirinkimas3;

                do {
                
                    cout << "Pasirinkite kriterija, pagal kuria norite rusiuoti duomenis:" << endl;
                    cout << "1. Rusiuoti pagal vardus." << endl;
                    cout << "2. Rusiuoti pagal pavardes." << endl;
                    cout << "3. Rusiuoti pagal galutini vidurki." << endl;
                    cout << "4. Rusiuoti pagal mediana." << endl;
                    cout << "Jusu pasirinkimas: ";
                    pasirinkimas3 = Pasirinkimas3();

                    if (pasirinkimas3 == 1) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_varda);
                    } else if (pasirinkimas3 == 2 ) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_pavarde);
                    } else if (pasirinkimas3 == 3) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki);
                    } else if (pasirinkimas3 == 4) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_mediana);
                    }
                
                  } while (pasirinkimas3 != 1 && pasirinkimas3 != 2 && pasirinkimas3 != 3 && pasirinkimas3 != 4);

                // Duomenu irasymas i faila "kursiokai.txt"
                ofstream fileName1("isvedimas.txt");

                fileName1 << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
                fileName1 << "-----------------------------------------------------------------" << endl;

                // Duomenu isvedimas
                for (const auto& studentas : studentai) {
                    fileName1 << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                    fileName1 << fixed << setprecision(2) << studentas.galutinis_vid << setw(30);
                    fileName1 << fixed << setprecision(2) << studentas.mediana << endl;
                }

                fileName1.close();

                auto end = chrono::steady_clock::now();
                double laikas = chrono::duration <double> (end - start).count();
                laikai.push_back(laikas);
                cout << "Trukme: " << laikas << " s" << endl;   
              
        } while (pasirinkimas2 != 0);

        // Skaiciuojama vidutine trukme
                double laiku_suma = 0.0;
                for (auto laikas : laikai) {
                    laiku_suma += laikas;
                }
        
        double laiku_vidurkis = (laikai.size() > 0) ? (laiku_suma / laikai.size()) : 0.0;
        cout << "Vidutine trukme: " << laiku_vidurkis << " s" << endl;

        break;

            }

            // Menu 5
            case 5:
            {
                cout << "Darbas baigtas." << endl;
                return 0;
            }
            default :
            {

                cout << "Ivyko klaida. Bandykite ivesti kita skaiciu. " << endl;
                break;
            }
        }
    }
}