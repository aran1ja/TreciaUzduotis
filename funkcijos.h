#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <list>
#include <deque>
#include "studentas.h"
#include "vector.h"

using namespace std;

double mediana(Vector<int> pazymiai, int egzamino_rezultatas);
double vidurkis_galutinis(double suma, int n, int egzamino_rezultatas);
bool palyginti_pagal_varda(const Studentas &a, const Studentas &b);
bool palyginti_pagal_pavarde(const Studentas &a, const Studentas &b);
bool palyginti_pagal_mediana(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki(const Studentas &a, const Studentas &b);
bool palyginti_pagal_galutini_vidurki_didejimo_tvarka(const Studentas &a, const Studentas &b);
bool ar_vargsiukas(const Studentas& student);
void RezultatuVaizdavimas (const Vector<Studentas>& studentai, int pasirinkimas1);
void generuotiFaila(string failoPavadinimas, int ndSkaicius, int studentuSkaicius);

// 1 strategija
void failoIsvedimasVector1(const Vector<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaVector1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void failoIsvedimasList1(const list<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaList1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void failoIsvedimasDeque1(const deque<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaDeque1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);

// 2 strategija
void nuskaitytiFailaVector2(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaList2(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaDeque2(string failoPavadinimas, string vargsiukuFailoPavadinimas);

// 3 strategija
void nuskaitytiFailaVector3(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaList3(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaDeque3(string failoPavadinimas, string vargsiukuFailoPavadinimas);

void testai();

#endif