#include "lib.h"
#include "studentas.h"


int main(){
    std::vector<Studentas> studentai;
    Studentas laikinasStud;

    int studSk, vidMed, ivedGener;

    std::cout << "Norite įvesti (0) ar generuoti (1)?: " << std::endl;
    std::cin >> ivedGener;

    if (ivedGener == 1){
        generate();
        exit(EXIT_SUCCESS);
    }

    std::cout << "Apie kiek studentų pildysite informaciją?:" << std::endl;
    std::cin >> studSk;
    std::cout << "Norite matyti vidurkį (0) ar medianą (1)?" << std::endl;
    std::cin >> vidMed;

    for (int i=0; i<studSk; i++){
        input(laikinasStud);
        studentai.push_back(laikinasStud);
        clean(laikinasStud);
    }

    if (vidMed == 0){
        std::cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::left << std::setw(20) << "Pavardė" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
    }
    
    for (int i=0; i<studSk; i++){
        output(studentai.at(i), vidMed);
    }

    return 0;
}