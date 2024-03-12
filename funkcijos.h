#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

using namespace std;

double mediana(vector<int> pazymiai, int egzamino_rezultatas);
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas);
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b);
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki_didejimo_tvarka(const Studentas &a, const Studentas &b);
void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1);
void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius);
// <vector> konteineris
void failoIsvedimasVector(const vector<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaVector(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
// <list> konteineris
void failoIsvedimasList(const list<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaList(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
// <deque> konteineris
void failoIsvedimasDeque(const deque<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaDeque(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);

#endif