#include <iostream>
using namespace std;

/*
    Pentru clasa Mașină creați
    1. Constructor cu parametri, default, de copiere
    2. Operator de atribuire, afisare, comparatie
    3. Adăugați un membru static, unul constant (pentru valoarea maximă). Verificați în main.
    4. Adăugați un membru alocat dinamic. 

*/

class Masina {
private:
    int putereCP;          // cai putere
    int anFabricatie; 
    bool isValidPutere(int p) const { return p >= 0 && p <= 1000; }

public:
    // ---------- Getteri ----------
    int getPutereCP()  { return putereCP; }
    int getAnFabricatie()  { return anFabricatie; }


    // ---------- Setteri ----------
    void setPutereCP(int cp) {
        if (isValidPutere(cp))
             putereCP = cp;
    }
    void setAnFabricatie(int an) { 
        anFabricatie = an; 
    } 

};