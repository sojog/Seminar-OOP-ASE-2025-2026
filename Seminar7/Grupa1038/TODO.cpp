#include <iostream>
using namespace std;

/*
    Pentru clasa Apartament creați
    1. Constructor de copiere
    2. Operator de atribuire, afisare, comparatie
*/

class Apartament {
    double pret;
    int suprafata;
public: 
    // Constructor cu parametri
    Apartament( int suprafata, double pret) : suprafata(suprafata), pret(pret) {
    }

};