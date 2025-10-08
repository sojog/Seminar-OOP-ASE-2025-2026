
#include <iostream>
using namespace std;

// CONVENTIE - numele de CLASA incepe cu litera MARE!!!!
// CLASA este un sablon 
class Calculator {
public:
    int x_calc_public;
    int y_calc_public;

    // FUNCTIE in interiorului clasei - (metoda)
    int adunare_calc(int a, int b) {
        return a + b; 
    }
}; // <- Punct si virgula dupa clasa


// CONVENTIE - numele de functie incepe cu litera mica
// FUNCTIE - procedurala
int adunare(int a, int b) {
    return a + b;
}

int main () {
    // PROCEDURAL
    // CONVENTIE - numele de variabila incepe cu litera mica
    int x = 30;
    int y = 40;

    int suma = adunare(x, y);
    cout << "Suma procedurala este:" << suma << endl;


    // OOP
    // Crearea unui obiect (conform conventie imi dau seama de tipul de date)
    Calculator obiect; // <- calc - este un OBIECT


    // Accesarea unei variabile din obiect
    cout << "Valoarea lui x_calc" << obiect.x_calc_public << endl;
    cout << "Valoarea lui y_calc" << obiect.y_calc_public << endl;


    obiect.x_calc_public = 400;
    obiect.y_calc_public = 333;

    cout << "Valoarea lui x_calc" << obiect.x_calc_public << endl;
    cout << "Valoarea lui y_calc" << obiect.y_calc_public << endl;


    cout << "Rezultatul adunarii a doua numere prin metoda adunare_calc:" << obiect.adunare_calc(11, 22) << endl;


}