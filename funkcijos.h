#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <list>
#include <deque>
#include "studentas.h"

using namespace std;

double mediana(vector<int> pazymiai, int egzamino_rezultatas);
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas);
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b);
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki_didejimo_tvarka(const Studentas &a, const Studentas &b);
bool ar_vargsiukas(const Studentas& student);
void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1);
void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius);

// 1 strategija
// <vector> konteineris
void failoIsvedimasVector1(const vector<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaVector1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
// <list> konteineris
void failoIsvedimasList1(const list<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaList1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
// <deque> konteineris
void failoIsvedimasDeque1(const deque<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaDeque1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);

// 2 strategija
void nuskaitytiFailaVector2(vector<Studentas>& studentai, string failoPavadinimas, string vargsiukuFailoPavadinimas);

#endif