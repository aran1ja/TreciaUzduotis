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
void failoIsvedimasVector1(const vector<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaVector1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void rusiuotiStudentusVector1(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void failoIsvedimasList1(const list<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaList1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void rusiuotiStudentusList1(list<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void failoIsvedimasDeque1(const deque<Studentas>& studentai, string failoPavadinimas);
void nuskaitytiFailaDeque1(string failoPavadinimas, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);
void rusiuotiStudentusDeque1(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas, string kietakiuFailoPavadinimas);

// 2 strategija
void nuskaitytiFailaVector2(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusVector2(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaList2(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusList2(list<Studentas>& studentai, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaDeque2(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusDeque2(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas);

// 3 strategija
void nuskaitytiFailaVector3(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusVector3(vector<Studentas>& studentai, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaList3(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusList3(list<Studentas>& studentai, string vargsiukuFailoPavadinimas);
void nuskaitytiFailaDeque3(string failoPavadinimas, string vargsiukuFailoPavadinimas);
void rusiuotiStudentusDeque3(deque<Studentas>& studentai, string vargsiukuFailoPavadinimas);

#endif