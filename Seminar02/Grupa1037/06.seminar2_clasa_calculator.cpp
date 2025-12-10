
#include <iostream>
using namespace std;

// CONVENTIE - numele de CLASA incepe cu litera MARE!!!!
// CLASA este un sablon 
class Calculator {
// PRIVATE - se pot accesa doar din clasa
private:
    int x;
    int y;

public:
    // GETTER - citesc valorile din obiect
    int getX () {
        return x;
    }
    int getY () {
        return y;
    }

    // SETTER - seteaza valorile in obiect
    void setX (int newValue) {
        x = newValue;
    }
    void setY (int newValue) {
        y = newValue;
    }

    // FUNCTIE in interiorului clasei - (metoda)
    int adunare() {
        return x + y; 
    }
}; // <- Punct si virgula dupa clasa




int main () {
    
    Calculator obiect_calculator;

    cout << "X initial:" << obiect_calculator.getX () << endl;
    obiect_calculator.setX(999);
    cout << "X dupa set:" << obiect_calculator.getX () << endl << endl;


    cout << "Y initial:" << obiect_calculator.getY () << endl;
    obiect_calculator.setY(111);
    cout << "Y dupa set:" << obiect_calculator.getY () << endl;


    cout << "Rezultatul metodei adunare:" << obiect_calculator.adunare() << endl << endl;


    Calculator alt_obiect;
    alt_obiect.setX(3);
    alt_obiect.setY(5);

    cout << "Rezultatul  metodei adunare (OBIECTUL SECUND):" << alt_obiect.adunare() << endl << endl;


}