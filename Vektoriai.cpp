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

using namespace std;

int m, n, menu; // m - studentu skaicius, n - namu darbu skaicius
int variantas_namu_darbas, variantas_studentas, pasirinkimas; 
double suma, vidurkis;
int MAX_ND = 30;
int MAX_STUDENTU = 30;

struct Studentas {
    vector<int> pazymiai;
    string vardas, pavarde;
    int egzamino_rezultatas;
    double galutinis_vid, mediana;
};

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

// Mediana
double mediana(vector<int> pazymiai, int egzamino_rezultatas) {
    pazymiai.push_back(egzamino_rezultatas);
    size_t kiekis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());

    if (kiekis % 2 == 0) {
        return (pazymiai[kiekis / 2 - 1] + pazymiai[kiekis / 2]) / 2.0;
    } else {
        return pazymiai[kiekis / 2];
    }
}

// Vidurkis
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas) {
    if (n == 0) {
        return 0.6 * egzamino_rezultatas;
    } else {
        return 0.4 * (suma / n) + 0.6 * egzamino_rezultatas;
    }
}
                
int main() {

    vector <Studentas> A;
    int n;
    int menu;
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

            vector<Studentas> studentai;
            ifstream fileName("studentai10000.txt");
            string eilute;

            if (!fileName.is_open()) {
                cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
                return 1;
            }

            // Neskaitoma pirma eilute is failo
            getline(fileName, eilute);

            while (getline(fileName, eilute)) {
                stringstream ss(eilute);
                Studentas naujas_studentas;
                int pazymiai, suma = 0;
                ss >> naujas_studentas.vardas >> naujas_studentas.pavarde;

                for (int i = 0; i < 15; i++) {
                    ss >> pazymiai;
                    naujas_studentas.pazymiai.push_back(pazymiai);
                    suma += pazymiai;
                }

                // Egzamino rezultatas
                ss >> naujas_studentas.egzamino_rezultatas;

                // Galutinio vidurkio ir medianos skaiciavimai
                naujas_studentas.galutinis_vid = (1.00 * suma / 15) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;
                naujas_studentas.mediana = mediana(naujas_studentas.pazymiai, naujas_studentas.egzamino_rezultatas);

                // Pridedamas studentas
                studentai.push_back(naujas_studentas);
            }

            fileName.close();

            // Duomenu irasymas i faila "kursiokai.txt"
            ofstream fileName1("kursiokai.txt");

            fileName1 << left << setw(15) << "Vardas" << setw(15) << "Pavarde " << setw(15) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
            fileName1 << "-----------------------------------------------------------------" << endl;

            // Duomenu isvedimas
            for (const auto& studentas : studentai) {
                fileName1 << left << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15);
                fileName1 << fixed << setprecision(2) << studentas.galutinis_vid << setw(30);
                fileName1 << fixed << setprecision(2) << studentas.mediana << endl;
            }

            fileName1.close();

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
