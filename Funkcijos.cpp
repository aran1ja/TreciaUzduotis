#include "funkcijos.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>
#include <list>
#include <deque>

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
// Rusiuojama pagal varda (didejimo tvarka)
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b) {
    return a.vardas < b.vardas;
}
// Rusiuojama pagal pavarde (didejimo tvarka)
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b) {
    return a.pavarde < b.pavarde;
}
// Rusiuojama pagal mediana (mazejimo tvarka)
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b) {
    return a.mediana > b.mediana;
}
// Rusiuojama pagal galutini vidurki (mazejimo tvarka)
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b) {
    return a.galutinis_vid > b.galutinis_vid;
}

bool palyginti_pagal_galutini_vidurki_didejimo_tvarka(const Studentas &a, const Studentas &b) {
    return a.galutinis_vid < b.galutinis_vid;
}

bool ar_vargsiukas(const Studentas& student) {
    return student.galutinis_vid < 5.0;
}

void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1) {

        switch (pasirinkimas1) {
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
}

void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius) {
    ofstream file(failoPavadinimas);
    //stringsream

    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    auto pradzios_laikas = chrono::steady_clock::now();

    file << setw(16) << left << "Vardas" << setw(17) << left << "Pavarde";

    for (int i = 1; i <= ndSkaicius; i++) {
        file << setw(10) << left << "ND" + to_string(i);
    }

    file << setw(10) << left << "Egz." << endl;

    // Generuojami irasai
    for (int i = 0; i < studentuSkaicius; i++) {
        file << "Vardas" << setw(10) << left << i + 1 << "Pavarde" << setw(10) << left << i + 1;

        // Generuojamas atsitiktiniai namu darbu pazymiai
        for (int j = 0; j < ndSkaicius; j++) {
                file << setw(10) << rand() % 10 + 1;
        }

        // Egzamino rezultatas
        file << setw(10) << rand() % 10 + 1 << endl;
    }

    file.close();

    auto pabaigos_laikas = chrono::steady_clock::now();
    auto laiko_skirtumas = chrono::duration <double> (pabaigos_laikas - pradzios_laikas).count();
    cout << "Failo kurimo ir uzdarymo laikas: " << fixed << setprecision(4) << laiko_skirtumas << "s" << endl;
}

//// 1 strategija

/// Vector
void failoIsvedimasVector1(const vector<Studentas>& studentai, string failoPavadinimas) {
    ofstream file(failoPavadinimas);
    
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    file << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    file << "--------------------------------------------------------" << endl;
    for (const auto& studentas : studentai) {
        file << setw(15) << left << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << fixed << setprecision(2) << studentas.galutinis_vid << endl;
    }

    file.close();
}

void nuskaitytiFailaVector1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);
    
    vector<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);
    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        
    
    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    

    fileName.close();

    rusiuotiStudentusVector1(studentai, vargsiukuFailoPavadinimas, kietakiuFailoPavadinimas);
}

void rusiuotiStudentusVector1(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
       
    // Padaromi 2 nauji konteineriai
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;
    double visasLaikas = 0.0;

    auto pradedam = chrono::steady_clock::now();

    // Studento pridėjimas į atitinkamą konteinerį
    for (const auto& studentas : studentai) {
        if (studentas.galutinis_vid < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }

    //studentas.clear();

    auto pabaigiam = chrono::steady_clock::now();
    auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
    visasLaikas += skaiciuojam;

    auto did_pradedame_v = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(kietiakai.begin(), kietiakai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_v = chrono::steady_clock::now();
    auto did_skaiciuojame_v = chrono::duration <double> (did_baigiame_v - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_v << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << visasLaikas << "s" << endl;

    // Issaugome vargsiukus ir kietakius atskiruose failuose
    failoIsvedimasVector1(vargsiukai, vargsiukuFailoPavadinimas);
    failoIsvedimasVector1(kietiakai, kietakiuFailoPavadinimas);
}
/// List
void failoIsvedimasList1(const list<Studentas>& studentai, string failoPavadinimas) {
    ofstream file(failoPavadinimas);
    
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    file << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    file << "--------------------------------------------------------" << endl;
    for (const auto& studentas : studentai) {
        file << setw(15) << left << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << fixed << setprecision(2) << studentas.galutinis_vid << endl;
    }

    file.close();
}

void nuskaitytiFailaList1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);
    
    list<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);
    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        
    
    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    

    fileName.close();

    rusiuotiStudentusList1(studentai, vargsiukuFailoPavadinimas, kietakiuFailoPavadinimas);
}

void rusiuotiStudentusList1(list<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
       
    // Padaromi 2 nauji konteineriai
    list<Studentas> vargsiukai;
    list<Studentas> kietiakai;

    auto pradedam = chrono::steady_clock::now();

    // Studento pridėjimas į atitinkamą konteinerį
    for (const auto& studentas : studentai) {
        if (studentas.galutinis_vid < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }

    //studentas.clear();

    auto pabaigiam = chrono::steady_clock::now();
    auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();

    auto did_pradedame_l = chrono::steady_clock::now();
    vargsiukai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    kietiakai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_l = chrono::steady_clock::now();
    auto did_skaiciuojame_l = chrono::duration <double> (did_baigiame_l - did_pradedame_l).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_l << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus ir kietakius atskiruose failuose
    failoIsvedimasList1(vargsiukai, vargsiukuFailoPavadinimas);
    failoIsvedimasList1(kietiakai, kietakiuFailoPavadinimas);
}
/// Deque
void failoIsvedimasDeque1(const deque<Studentas>& studentai, string failoPavadinimas) {
    ofstream file(failoPavadinimas);
    
    if (!file.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    file << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    file << "--------------------------------------------------------" << endl;
    for (const auto& studentas : studentai) {
        file << setw(15) << left << studentas.vardas << setw(15) << studentas.pavarde << setw(20) << fixed << setprecision(2) << studentas.galutinis_vid << endl;
    }

    file.close();
}

void nuskaitytiFailaDeque1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);
    
    deque<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);
    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        
    
    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    

    fileName.close();

    rusiuotiStudentusDeque1(studentai, vargsiukuFailoPavadinimas, kietakiuFailoPavadinimas);
}

void rusiuotiStudentusDeque1(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas) {
       
    // Padaromi 2 nauji konteineriai
    deque<Studentas> vargsiukai;
    deque<Studentas> kietiakai;

    auto pradedam = chrono::steady_clock::now();

    // Studento pridėjimas į atitinkamą konteinerį
    for (const auto& studentas : studentai) {
        if (studentas.galutinis_vid < 5.0) {
            vargsiukai.push_back(studentas);
        } else {
            kietiakai.push_back(studentas);
        }
    }

    //studentas.clear();

    auto pabaigiam = chrono::steady_clock::now();
    auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();

    auto did_pradedame_d = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(kietiakai.begin(), kietiakai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_d = chrono::steady_clock::now();
    auto did_skaiciuojame_d = chrono::duration <double> (did_baigiame_d - did_pradedame_d).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_d << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus ir kietakius atskiruose failuose
    failoIsvedimasDeque1(vargsiukai, vargsiukuFailoPavadinimas);
    failoIsvedimasDeque1(kietiakai, kietakiuFailoPavadinimas);
}

//// 2 strategija

void nuskaitytiFailaVector2(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);

    vector<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusVector2(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusVector2(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        vector<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Pasaliname vargsiukus is bendro konteinerio
        studentai.erase(remove_if(studentai.begin(), studentai.end(), ar_vargsiukas), studentai.end());

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_v = chrono::steady_clock::now();
    auto did_skaiciuojame_v = chrono::duration <double> (did_baigiame_v - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_v << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasVector1(vargsiukai, vargsiukuFailoPavadinimas);
}

void nuskaitytiFailaList2(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);
    list<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusList2(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusList2(list<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        list<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Pasaliname vargsiukus is bendro konteinerio
        studentai.erase(remove_if(studentai.begin(), studentai.end(), ar_vargsiukas), studentai.end());

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    vargsiukai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    studentai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_d = chrono::steady_clock::now();
    auto did_skaiciuojame_d = chrono::duration <double> (did_baigiame_d - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_d << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasList1(vargsiukai, vargsiukuFailoPavadinimas);
}

void nuskaitytiFailaDeque2(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);

    deque<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusDeque2(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusDeque2(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        deque<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Pasaliname vargsiukus is bendro konteinerio
        studentai.erase(remove_if(studentai.begin(), studentai.end(), ar_vargsiukas), studentai.end());

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_d = chrono::steady_clock::now();
    auto did_skaiciuojame_d = chrono::duration <double> (did_baigiame_d - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_d << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasDeque1(vargsiukai, vargsiukuFailoPavadinimas);
}

//// 3 strategija

void nuskaitytiFailaVector3(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);

    vector<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusVector3(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusVector3(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        vector<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Ieskome vargsiuku ir triname juos is studentu vektoriaus
        auto paieska = find_if(studentai.begin(), studentai.end(), ar_vargsiukas);

        if (paieska != studentai.end()) {
            studentai.erase(remove_if(paieska, studentai.end(), ar_vargsiukas), studentai.end());
        }

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_v = chrono::steady_clock::now();
    auto did_skaiciuojame_v = chrono::duration <double> (did_baigiame_v - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_v << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasVector1(vargsiukai, vargsiukuFailoPavadinimas);
}

void nuskaitytiFailaList3(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);
    list<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusList3(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusList3(list<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        list<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Ieskome vargsiuku ir triname juos is studentu vektoriaus
        auto paieska = find_if(studentai.begin(), studentai.end(), ar_vargsiukas);

        if (paieska != studentai.end()) {
            studentai.erase(remove_if(paieska, studentai.end(), ar_vargsiukas), studentai.end());
        }

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    vargsiukai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    studentai.sort(palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_d = chrono::steady_clock::now();
    auto did_skaiciuojame_d = chrono::duration <double> (did_baigiame_d - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_d << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasList1(vargsiukai, vargsiukuFailoPavadinimas);
}

void nuskaitytiFailaDeque3(string failoPavadinimas, string vargsiukuFailoPavadinimas) {
    ifstream fileName(failoPavadinimas);

    deque<Studentas> studentai;
    string eilute;

    if (!fileName.is_open()) {
        cout << "Nepavyko atidaryti failo. Bandykite dar karta." << endl;
        return;
    }

    double skaicius = 0.0;
    string smth;
    double nuskaitymoLaikas = 0.0;

    // Nustatomas skaicius (ND ir Egz.) iki zymos "Egz."
    while (smth != "Egz.") {
        fileName >> smth;
        skaicius++;
    }

    skaicius = skaicius - 3; // Istrinamos pirmos eilutes nereikalingi skaiciai

    // Neskaitoma pirma eilute is failo
    getline(fileName, eilute);

    while (getline(fileName, eilute)) {

        auto ppradzia = chrono::steady_clock::now();

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
        auto ppabaiga = chrono::steady_clock::now();
        auto sskirtumas = chrono::duration <double> (ppabaiga - ppradzia).count();
        nuskaitymoLaikas += sskirtumas;

        // Galutinio vidurkio skaiciavimas
        naujas_studentas.galutinis_vid = (1.00 * suma / skaicius) * 0.4 + naujas_studentas.egzamino_rezultatas * 0.6;

        studentai.push_back(naujas_studentas);
    }        

    cout << "Duomenu nuskaitymo is failo laikas: " << fixed << setprecision(4) << nuskaitymoLaikas << "s" << endl;    
    fileName.close();
    rusiuotiStudentusDeque3(studentai, vargsiukuFailoPavadinimas);
}

void rusiuotiStudentusDeque3(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas) {
        deque<Studentas> vargsiukai;

        auto pradedam = chrono::steady_clock::now();

        // Tikriname ar studentas yra vargsiukas
        for (const auto& studentas : studentai) {
            if (studentas.galutinis_vid < 5.0) {
                vargsiukai.push_back(studentas);
            } 
        }

        // Ieskome vargsiuku ir triname juos is studentu vektoriaus
        auto paieska = find_if(studentai.begin(), studentai.end(), ar_vargsiukas);

        if (paieska != studentai.end()) {
            studentai.erase(remove_if(paieska, studentai.end(), ar_vargsiukas), studentai.end());
        }

        auto pabaigiam = chrono::steady_clock::now();
        auto skaiciuojam = chrono::duration <double> (pabaigiam - pradedam).count();
        
    // Tikriname, ar vargsiukai buvo perkelti
    if (!vargsiukai.empty()) {
            cout << "Vargsiukai sekmingai perkelti i atskira konteineri." << endl;
        } else {
            cout << "Nepavyko perkelti vargsiuku." << endl;
        }

    auto did_pradedame_v = chrono::steady_clock::now();
    sort(vargsiukai.begin(), vargsiukai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    sort(studentai.begin(), studentai.end(), palyginti_pagal_galutini_vidurki_didejimo_tvarka);
    auto did_baigiame_d = chrono::steady_clock::now();
    auto did_skaiciuojame_d = chrono::duration <double> (did_baigiame_d - did_pradedame_v).count();

    cout << "Studentu rusiavimo didejimo tvarka laikas: " << fixed << setprecision(4) << did_skaiciuojame_d << "s" << endl;
    cout << "Studentu rusiavimo i dvi grupes laikas: " << fixed << setprecision(4) << skaiciuojam << "s" << endl;

    // Issaugome vargsiukus atskirame faile
    failoIsvedimasDeque1(vargsiukai, vargsiukuFailoPavadinimas);
}
