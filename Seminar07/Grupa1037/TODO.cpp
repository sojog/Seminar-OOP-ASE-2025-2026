#include <iostream>
using namespace std;

/*
    Pentru clasa Angajat creați
    1. Constructor de copiere
    2. Operator de atribuire, afisare, comparatie
*/

class Angajat {
    int varsta;
    double salariu;
public: 
    // Constructor cu parametri
    Angajat( int varsta, double salariu) : varsta(varsta), salariu(salariu) {
    }

};