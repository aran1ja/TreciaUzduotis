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
string raide;
             
int main() {

    vector<Studentas> studentai;

    while (true) {

        // Menu
        cout << "--------------------------------------------------" << endl;
        cout << "Isrinkite programos eigos buda paspaudus nurodyta skaiciu." << endl;
        cout << "1. Visi duomenys ivedami ranka. " << endl;
        cout << "2. Studento duomenys ivedami ranka, o pazymiai generuojami programos. " << endl;
        cout << "3. Visa informacija yra programos generuojama." << endl;
        cout << "4. Nuskaityti duomenis is failo. " << endl;
        cout << "5. Generuoti failus ir surusiuoti duomenis." << endl;
        cout << "6. Baigti darba." << endl;
        cout << "Jusu pasirinkimas: "; 

        try {

            cin >> menu;                  
        
                if (cin.fail() || cin.peek() != '\n' || menu < 1 || menu > 6) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    throw invalid_argument("Ivestas netinkamas simbolis.");

                }
                    getline(cin, raide);

                if (!raide.empty()) {
                    throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                }

    

        } catch (const invalid_argument& iu) {
            cout << iu.what() << endl;
        }

        switch (menu) {

            // Menu 1 - duomenys ivedami ranka
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

                while (true) {
                try {

                    cin >> n;
                    
                    if (cin.fail() || cin.peek() != '\n') {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik namu darbu skaiciu.");
                    }

                    if(n < 0) {
                        throw invalid_argument("Netinkamas namu darbu skaicius. Bandykite ivesti kita skaiciu.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& n_klaida) {
                    cout << n_klaida.what() << endl;
                }
            }

               for (int j = 0; j < n; j++) {
                int pazymiai;

                cout << "Studento pazymis uz " << j + 1 << " namu darba: ";

                while (true) {
                    try {
                        cin >> pazymiai;

                        if (cin.fail() || cin.peek() != '\n' || pazymiai > 10 || pazymiai < 1) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu.");
                        }

                        getline(cin, raide);

                        if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                        }

                        break;

                    } catch (const invalid_argument& pazymis_klaida) {
                        cout << pazymis_klaida.what() << endl;
                    }
                }

                naujas_studentas.pazymiai.push_back(pazymiai);
            }
            
            int ivestis_variantas_nd;
            do {

                cout << "Ar norite ivesti dar vieno namu darbo pazymi?\nJeigu ne, spauskite 0.\nJeigu taip, spauskite 1. ";
                 

                while (true) {
                    try {
                        cin >> ivestis_variantas_nd;

                        if (cin.fail() || cin.peek() != '\n') {
                            throw invalid_argument("Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1).");
                        }

                        if (ivestis_variantas_nd != 0 && ivestis_variantas_nd != 1) {
                            throw invalid_argument("Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1).");
                        }

                        break;
                    } catch (const invalid_argument& ivestis_variantas_nd_klaida) {
                        cout << ivestis_variantas_nd_klaida.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                // Pridedamas dar vienas studentas
                if (ivestis_variantas_nd == 1) {
                    n++;
                    int pazymiai;

            while (true) {
                try {

                    cout << "Studento pazymis uz " << n << " namu darba: ";   
                    cin >> pazymiai;

                    if (cin.fail() || cin.peek() != '\n' || pazymiai > 10 || pazymiai < 1) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu.");
                        }

                        getline(cin, raide);

                        if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                        }

                    break;

                } catch (const invalid_argument& pazymiai_klaida) {
                    cout << pazymiai_klaida.what() << endl;                        
                }   
            }

            naujas_studentas.pazymiai.push_back(pazymiai); // Pazymis pridedamas prie pazymiu vektoriu
            suma += pazymiai;
        }

                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);
                    
                    
                } while (ivestis_variantas_nd != 0);

                // Egzamino rezultatas
                cout << "Studento egzamino rezultatas: ";
                int rezultatas;

                while (true) {
                try {

                    cin >> rezultatas;

                    if (cin.fail() || cin.peek() != '\n') {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    if (rezultatas > 10 || rezultatas < 1) {
                        throw invalid_argument("Ivyko klaida. Prasau irasykite skaiciu nuo 1 iki 10.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& egz_klaida) {
                    cout << egz_klaida.what() << endl;
                }
            }

                naujas_studentas.egzamino_rezultatas = rezultatas;

                // Skaiciuoja suma visu pazymiu 
                double suma = 0.0;
                for (int pazymis : naujas_studentas.pazymiai) {
                    suma += pazymis;
                }

                // Galutinio vidurkio ir medianos skaiciavimai
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);

                cout << "--------------------------------------------------" << endl;
                cout << "Ar norite prideti dar vieno studento duomenis?" << endl;
                cout << "Jeigu ne, spauskite 0. Jeigu taip, spauskite 1. ";

                while (true) {
                    try {
                        cin >> variantas_studentas;

                        if (cin.fail() || cin.peek() != '\n') {
                            throw invalid_argument("Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1).");
                        }

                        if (variantas_studentas != 0 && variantas_studentas != 1) {
                            throw invalid_argument("Ivyko klaida. Bandykite ivesti kita skaiciu (0 arba 1).");
                        }

                        break;
                    } catch (const invalid_argument& variantas_studentas_klaida) {
                        cout << variantas_studentas_klaida.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                if (variantas_studentas == 0)
                    break;
                }

            // Vartotojas, ivedamas duomenis ranka, pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail() || cin.peek() != '\n') {
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            } 

            // Menu 2 - duomenys ivedami ranka, pazymiai generuojami programos
            case 2:
            {

            srand(time(NULL));

            vector<Studentas> studentai;
            cout << "Kiek yra studentu? ";

            while (true) {
                try {

                    cin >> m;

                    if (cin.fail() || cin.peek() != '\n') {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        throw invalid_argument("Klaida. Iveskite tik studentu skaiciu.");
                    }

                    if(m <= 0) {
                        throw invalid_argument("Netinkamas studentu skaicius. Bandykite ivesti kita skaiciu.");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;

                } catch (const invalid_argument& m_klaida) {
                    cout << m_klaida.what() << endl;

                }
            }

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

                // Galutinio vidurkio ir medianos skaiciavimai
                naujas_studentas.galutinis_vid = vidurkis_galutinis(suma, n, naujas_studentas.egzamino_rezultatas);
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                studentai.push_back(naujas_studentas);
            
            }

            // Vartotojas pats issirenka ka nori atvaizduoti: vidurki ar mediana
            cout << "Ka programa turi atvaizduoti?" << endl;
            cout << "Jeigu reikalingas vidurkis, spauskite 1." << endl;
            cout << "Jeigu reikalinga mediana, spauskite 2." << endl;
            cout << "Jeigu reikalingas ir vidurkis, ir mediana, spauskite 3." << endl;
            cout << "Jusu pasirinkimas: ";
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail() || cin.peek() != '\n') {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            }

            // Menu 3 - duomenys generuojami programos
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
            int pasirinkimas1;

            while (true) {
                try {
                    cin >> pasirinkimas1;

                    if (cin.fail() || cin.peek() != '\n') {
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Klaida. Ivestas netinkamas simbolis. Irasykite viena is nurodytu skaiciu.");
                    }

                    if (pasirinkimas1 != 1 && pasirinkimas1 != 2 && pasirinkimas1 != 3) {
                        throw invalid_argument("Klaida. Irasykite skaiciu (1, 2 arba 3).");
                    }

                    getline(cin, raide);

                    if (!raide.empty()) {
                        throw invalid_argument("Klaida. Iveskite tik skaiciu.");
                    }

                    break;
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }

            RezultatuVaizdavimas(studentai, pasirinkimas1);
            break;
            }

            // Menu 4 - duomenys nuskaitomi is failu
            case 4: 
            {
            
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
            cout << "Jusu pasirinkimas: "; cin >> pasirinkimas2;

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

            if (!fileName.is_open()) {
                cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
                return 0;
            }

            auto start = chrono::steady_clock::now();

                // Neskaitoma pirma eilute is failo
                getline(fileName, eilute);

                while (getline(fileName, eilute)) {
                    stringstream ss(eilute);
                    Studentas naujas_studentas;
                    int pazymiai, skaicius_pazymiu = 0;
                    ss >> naujas_studentas.vardas >> naujas_studentas.pavarde;

                    while(ss >> pazymiai){
                        if(!ss.eof()){
                        
                        // Namu darbu pazymiai
                        naujas_studentas.pazymiai.push_back(pazymiai);
                        skaicius_pazymiu++; 
                        } else {

                        // Egzamino rezultatas
                        naujas_studentas.egzamino_rezultatas = pazymiai;
                        }
                    }

                    double pazymiu_suma = 0.0;
                    for (int pazymiai : naujas_studentas.pazymiai) {
                        pazymiu_suma += pazymiai;
                    }

                    // Galutinio vidurkio ir medianos skaiciavimai
                    naujas_studentas.galutinis_vid = (1.00 * pazymiu_suma / skaicius_pazymiu) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;
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
                    cin >> pasirinkimas3;

                           if (pasirinkimas3 == 1) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_varda);
                    } else if (pasirinkimas3 == 2) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_pavarde);
                    } else if (pasirinkimas3 == 3) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki);
                    } else if (pasirinkimas3 == 4) {
                        sort(studentai.begin(), studentai.end(), palyginti_pagal_mediana);
                    } else {
                        cout << "Neteisingas skaicius. Bandykite dar karta." << endl;
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

            // Menu 5 - failai generuojami ir duomenys rusiuojami
            case 5:
            {
                
            vector<Studentas> studentai;
            list<Studentas> studentai_list;
            deque<Studentas> studentai_deque;

            int pasirinkimas4;

            while (true) {

                cout << "Ar norite sugeneruoti naujus failus?" << endl;
                cout << "Spauskite 1, jeigu taip. Jeigu ne, spauskite bet koki kita skaiciu." << endl;
                
                if (!(cin >> pasirinkimas4)) {
                    cout << "Klaida. Ivestas netinkamas simbolis. Iveskite skaiciu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; // Sugrįžkite į ciklo pradžią, kad vartotojas galėtų bandyti iš naujo.
                }

                if (pasirinkimas4 != 1) {
                    cout << " " << endl;
                    break; // Jei vartotojas ne nori generuoti failų, nutraukti ciklą.
                }

                try {
                    generuotiFaila("studentu1000.txt", 15, 1000);
                    generuotiFaila("studentu10000.txt", 10, 10000);
                    generuotiFaila("studentu100000.txt", 7, 100000);
                    generuotiFaila("studentu1000000.txt", 3, 1000000);
                    generuotiFaila("studentu10000000.txt", 1, 10000000);
                    break; // Nutraukti ciklą, jei pavyko sugeneruoti failus be klaidų.
                } catch (const invalid_argument& pasirinkimo_klaida) {
                    cout << pasirinkimo_klaida.what() << endl;
                }
            }
                
                cout << "//////////////////////////////////////////////////";
                cout << "1 STRATEGIJA";
                cout << "//////////////////////////////////////////////////" << endl;  


                cout << "--------------------------------------------------";
                cout << "Anksciau sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;

                auto start1 = chrono::steady_clock::now();
                cout << "studentai10000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentai10000.txt", "av.vargsiukai10000.txt", "av.kietiakiai10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentai10000.txt", "al.vargsiukai10000.txt", "al.kietiakiai10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentai10000.txt", "ad.vargsiukai10000.txt", "ad.kietiakiai10000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai100000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentai100000.txt", "av.vargsiukai100000.txt", "av.kietiakiai100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentai100000.txt", "al.vargsiukai100000.txt", "al.kietiakiai100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentai100000.txt", "ad.vargsiukai100000.txt", "ad.kietiakiai100000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai1000000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentai1000000.txt", "av.vargsiukai1000000.txt", "av.kietiakiai1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentai1000000.txt", "al.vargsiukai1000000.txt", "al.kietiakiai1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentai1000000.txt", "ad.vargsiukai1000000.txt", "ad.kietiakiai1000000.txt");

                cout << "---------------------------------------------------------------------" << endl;
                cout << "kursiokai.txt failas" << endl;    
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("kursiokai.txt", "av.kursiokai_vargsiukai.txt", "av.kursiokai_kietiakiai.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("kursiokai.txt", "al.kursiokai_vargsiukai.txt", "al.kursiokai_kietiakiai.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("kursiokai.txt", "ad.kursiokai_vargsiukai.txt", "ad.kursiokai_kietiakiai.txt");      

                cout << "--------------------------------------------------";
                cout << "Nauji sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;

                cout << "1000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentu1000.txt", "v.vargsiukai1000.txt", "v.kietiakiai1000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentu1000.txt", "l.vargsiukai1000.txt", "l.kietiakiai1000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentu1000.txt", "d.vargsiukai1000.txt", "d.kietiakiai1000.txt");

                cout << "---------------------------------------------------------------------" << endl;
                cout << "10000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentu10000.txt", "v.vargsiukai10000.txt", "v.kietiakiai10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentu10000.txt", "l.vargsiukai10000.txt", "l.kietiakiai10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentu10000.txt", "d.vargsiukai10000.txt", "d.kietiakiai10000.txt");

                cout << "---------------------------------------------------------------------" << endl;
                cout << "100000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentu100000.txt", "v.vargsiukai100000.txt", "v.kietiakiai100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentu100000.txt", "l.vargsiukai100000.txt", "l.kietiakiai100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentu100000.txt", "d.vargsiukai100000.txt", "d.kietiakiai100000.txt");
              
                cout << "---------------------------------------------------------------------" << endl;
                cout << "1000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentu1000000.txt", "v.vargsiukai1000000.txt", "v.kietiakiai1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentu1000000.txt", "l.vargsiukai1000000.txt", "l.kietiakiai1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentu1000000.txt", "d.vargsiukai1000000.txt", "d.kietiakiai1000000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "10000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector1("studentu10000000.txt", "v.vargsiukai10000000.txt", "v.kietiakiai10000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList1("studentu10000000.txt", "l.vargsiukai10000000.txt", "l.kietiakiai10000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque1("studentu10000000.txt", "d.vargsiukai10000000.txt", "d.kietiakiai10000000.txt");
                auto end1 = chrono::steady_clock::now();
                auto difference1 = chrono::duration <double> (end1 - start1).count();   
                cout << "Vidutinis 1 strategijos veikimo laikas: " << 1.0 * difference1 / 9.0 << "s" << endl;  
                 
                cout << "//////////////////////////////////////////////////";
                cout << "2 STRATEGIJA";
                cout << "//////////////////////////////////////////////////" << endl;    

                cout << "--------------------------------------------------";
                cout << "Anksciau sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;

                auto start2 = chrono::steady_clock::now();
                cout << "studentai10000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "av2.vargsiukai10000.txt", "av2.kietiakiai10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "al2.vargsiukai10000.txt", "al2.kietiakiai10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "ad2.vargsiukai10000.txt", "ad2.kietiakiai10000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai100000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "av2.vargsiukai100000.txt", "av2.kietiakiai100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "al2.vargsiukai100000.txt", "al2.kietiakiai100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "ad2.vargsiukai100000.txt", "ad2.kietiakiai100000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai1000000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "av2.vargsiukai1000000.txt", "av2.kietiakiai1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "al2.vargsiukai1000000.txt", "al2.kietiakiai1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "ad2.vargsiukai1000000.txt", "ad2.kietiakiai1000000.txt");

                cout << "---------------------------------------------------------------------" << endl;
                cout << "kursiokai.txt failas" << endl;    
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "av2.kursiokai_vargsiukai.txt", "av2.kursiokai_kietiakiai.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "al2.kursiokai_vargsiukai.txt", "al2.kursiokai_kietiakiai.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "ad2.kursiokai_vargsiukai.txt", "ad2.kursiokai_kietiakiai.txt");      

                cout << "--------------------------------------------------";
                cout << "Nauji sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;  

                cout << "--------------------------------------------------" << endl;
                cout << "1000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "studentu1000.txt", "2v.vargsiuku1000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "studentu1000.txt", "2l.vargsiuku1000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "studentu1000.txt", "2d.vargsiuku1000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "10000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "studentu10000.txt", "2v.vargsiuku10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "studentu10000.txt", "2l.vargsiuku10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "studentu10000.txt", "2d.vargsiuku10000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "100000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "studentu100000.txt", "2v.vargsiuku100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "studentu100000.txt", "2l.vargsiuku100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "studentu100000.txt", "2d.vargsiuku100000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "1000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "studentu1000000.txt", "2v.vargsiuku1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "studentu1000000.txt", "2l.vargsiuku1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "studentu1000000.txt", "2d.vargsiuku1000000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "10000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector2(studentai, "studentu10000000.txt", "2v.vargsiuku10000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList2(studentai_list, "studentu10000000.txt", "2l.vargsiuku10000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque2(studentai_deque, "studentu10000000.txt", "2d.vargsiuku10000000.txt");    
                auto end2 = chrono::steady_clock::now();
                auto difference2 = chrono::duration <double> (end2 - start2).count();   
                cout << "Vidutinis 2 strategijos veikimo laikas: " << 1.0 * difference2 / 9.0 << "s" << endl;       

                cout << "//////////////////////////////////////////////////";
                cout << "3 STRATEGIJA";
                cout << "//////////////////////////////////////////////////" << endl;  

                cout << "--------------------------------------------------";
                cout << "Anksciau sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;

                auto start3 = chrono::steady_clock::now();
                cout << "studentai10000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "av2.vargsiukai10000.txt", "av2.kietiakiai10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "al2.vargsiukai10000.txt", "al2.kietiakiai10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "ad2.vargsiukai10000.txt", "ad2.kietiakiai10000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai100000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "av2.vargsiukai100000.txt", "av2.kietiakiai100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "al2.vargsiukai100000.txt", "al2.kietiakiai100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "ad2.vargsiukai100000.txt", "ad2.kietiakiai100000.txt");
                
                cout << "---------------------------------------------------------------------" << endl;
                cout << "studentai1000000.txt failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "av2.vargsiukai1000000.txt", "av2.kietiakiai1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "al2.vargsiukai1000000.txt", "al2.kietiakiai1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "ad2.vargsiukai1000000.txt", "ad2.kietiakiai1000000.txt");

                cout << "---------------------------------------------------------------------" << endl;
                cout << "kursiokai.txt failas" << endl;    
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "av2.kursiokai_vargsiukai.txt", "av2.kursiokai_kietiakiai.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "al2.kursiokai_vargsiukai.txt", "al2.kursiokai_kietiakiai.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "ad2.kursiokai_vargsiukai.txt", "ad2.kursiokai_kietiakiai.txt");      

    

                cout << "--------------------------------------------------";
                cout << "Nauji sugeneruoti failai";
                cout << "--------------------------------------------------" << endl;

                cout << "--------------------------------------------------" << endl;
                cout << "1000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "studentu1000.txt", "3v.vargsiuku1000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "studentu1000.txt", "3l.vargsiuku1000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "studentu1000.txt", "3d.vargsiuku1000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "10000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "studentu10000.txt", "3v.vargsiuku10000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "studentu10000.txt", "3l.vargsiuku10000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "studentu10000.txt", "3d.vargsiuku10000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "100000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "studentu100000.txt", "3v.vargsiuku100000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "studentu100000.txt", "3l.vargsiuku100000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "studentu100000.txt", "3d.vargsiuku100000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "1000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "studentu1000000.txt", "3v.vargsiuku1000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "studentu1000000.txt", "3l.vargsiuku1000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "studentu1000000.txt", "3d.vargsiuku1000000.txt");

                cout << "--------------------------------------------------" << endl;
                cout << "10000000 studentu failas" << endl;
                cout << "Vector" << endl;
                nuskaitytiFailaVector3(studentai, "studentu10000000.txt", "3v.vargsiuku10000000.txt");
                cout << "List" << endl;
                nuskaitytiFailaList3(studentai_list, "studentu10000000.txt", "3l.vargsiuku10000000.txt");
                cout << "Deque" << endl;
                nuskaitytiFailaDeque3(studentai_deque, "studentu10000000.txt", "3d.vargsiuku10000000.txt");   
                auto end3 = chrono::steady_clock::now();
                auto difference3 = chrono::duration <double> (end3 - start3).count();   
                cout << "Vidutinis 3 strategijos veikimo laikas: " << 1.0 * difference3 / 9.0 << "s" << endl;  

                break;
            }

            // Menu 6 - darbas baigiamas
            case 6:
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