#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "lib.h"

struct Studentas{
    std::string vardas;
    std::string pavarde;
    std::vector<int> tarpRez;
    int egzamRez;
    double vidurkis, mediana;
};

void input(Studentas &Lok);
void output(Studentas Lok, int vidMed);
void clean(Studentas &Lok);

#endif