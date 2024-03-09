#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include "studentas.h"

using namespace std;

double mediana(vector<int> pazymiai, int egzamino_rezultatas);
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas);
double skaiciuotiVidurki(const std::vector<int>& nd);
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b);
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b);
void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1);
void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius);
void failoIsvedimas(const vector<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFaila(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void studentuRusiavimas(vector<Studentas>& naujas_studentas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);

#endif 