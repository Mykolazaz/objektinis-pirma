#include "lib.h"
#include "studentas.h"

double mediana(std::vector<int> &v){
    size_t n = v.size();
    sort(v.begin(), v.end());
    if (n % 2 == 0) {
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    } else {
        return v[n/2];
    }
}

void input(Studentas &Lok){
    int arRandom;
    std::string input;
    bool praeitasBuvoTuscias = false;

    std::cout << "Ar atsitiktinai generuoti sekančio studento balus? (0 arba 1):" << std::endl;
    std::cin >> arRandom;

    std::cout << "Įveskite studento vardą ir pavardę:" << std::endl;
    std::cin >> Lok.vardas >> Lok.pavarde;
    
    if (arRandom == 0){
        std::cout << "Įveskite egzamino rezultatą: " << std::endl;
        std::cin >> Lok.egzamRez;
        std::cout << "Į vieną eilutę įveskite tarpinius rezultatus (2 ENTER paspausdimai stabdo įvedimą):" << std::endl;

        while (true) {
            std::getline(std::cin, input);

            if (input.empty()) {
                if (praeitasBuvoTuscias) {
                    break;
                }
                praeitasBuvoTuscias = true;
            } else {
                praeitasBuvoTuscias = false;

                std::stringstream ss(input);
                int skaicius;
                
                while (ss >> skaicius) {
                    Lok.tarpRez.push_back(skaicius);
                }
            }
        }
    } else {
        std::srand(std::time(0));
        Lok.egzamRez = rand() % 10 + 1;
        for (int i = 0; i < 5; i++){
            Lok.tarpRez.push_back(rand() % 10 + 1);
        }
    }
    
}

void output(Studentas Lok, int vidMed){
    if(vidMed == 0){
        double vidurkis = (accumulate(Lok.tarpRez.begin(), Lok.tarpRez.end(), 0.0)+Lok.egzamRez)/(Lok.tarpRez.size() + 1);
        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20)<< std::setprecision(2) << std::fixed <<
        vidurkis << std::endl;
    } else {
        std::vector<int> visiRez = Lok.tarpRez;
        visiRez.push_back(Lok.egzamRez);
        double med = mediana(visiRez);

        std::cout << std::left << std::setw(20) << Lok.pavarde
        << std::setw(20) << Lok.vardas << std::setw(20) << std::setprecision(2) << std::fixed <<
        med << std::endl;
    }
    
}

void clean(Studentas &Lok){
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.tarpRez.clear();
}