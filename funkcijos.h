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
int Studentai();
int NamuDarbai();
int Pazymiai();
int EgzaminoRezultatas();
int Pasirinkimas1();
int Pasirinkimas2();
int Pasirinkimas3();
int VariantasNamuDarbas();
int VariantasStudentas();
int Menu();
void RezultatuVaizdavimas (const vector<Studentas>& studentai, int pasirinkimas1);

#endif 