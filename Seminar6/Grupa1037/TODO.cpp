#include <iostream>
using namespace std;

/*
    Pentru clasa Culoare creați
    1. Constructor cu parametri, default, de copiere
    2. Operator de atribuire, afisare, comparatie
    3. Adăugați un membru static, unul constant (pentru valoarea maximă). Verificați în main.
    4. Adăugați un membru alocat dinamic. 
    

*/

class Culoare {
private:
    int rosu;
    int verde;
    int albastru;
    bool isValidValue(int newValue) {
        return ((newValue >= 0) && (newValue <= 255));
    }

public:
   
    int getRosu() {
         return rosu;
    }
    void setRosu(int newValue) {
        if (isValidValue(newValue))
            rosu = newValue;
    }
    int getAlbastru() {
        return albastru;
    }
    void setAlbastru(int newValue) {
        if (isValidValue(newValue))
            albastru = newValue;
    }
    int getVerde() {
        return verde;
    }
    void setVerde(int newValue) {
        if (isValidValue(newValue))
            verde = newValue;
    }
};