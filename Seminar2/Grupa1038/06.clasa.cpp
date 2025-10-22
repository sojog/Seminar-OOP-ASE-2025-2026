
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std; 


// CLASA este un sablon - din ea se pot crea mai multe obiecte
// numele clasei - (CONVENTIE) cu litera mare
class Calculator {

// x, y
private:
    // PRIVATE - nu poate fi accesat din afara clasei
    int x, y;

    // INCAPSULARE
    void functie_privata() {
        cout << "Functia PRIVATA este accesata !!!" << endl;
    }

public:

    void functie_care_acceseaza_functia_privata () {
        functie_privata();
    }

    // GETTER - citire
    int getX(){
        return x;
    }
    // GETTER
    int getY(){
        return y;
    }
    // SETTER  - scriere
    void setX(int newValue){
       x = newValue; 
    }
    // GETTER
    void setY (int newValue) {
        y = newValue;
    }

    int cel_mai_mare_numar(){
        if (x > y) 
            return x;
        return y;
    }

    int suma() {
        return x + y;
    }

};


int main () {
    // Crearea unui obiect prin valoare
    Calculator obj_calc;
    // Crearea unui obiect prin referinta
    Calculator *ptr_calc = new Calculator();
    
    cout << "Valorea lui x:" << obj_calc.getX() << endl;
    cout << "Valorea lui y:" << obj_calc.getY() << endl;
    obj_calc.setX(22);
    obj_calc.setY(33);
    cout << "Valorea lui x:" << obj_calc.getX() << endl;
    cout << "Valorea lui y:" << obj_calc.getY() << endl;


    Calculator alt_obj_calc;
    cout << "Valorea lui x:" << alt_obj_calc.getX() << endl;
    cout << "Valorea lui y:" << alt_obj_calc.getY() << endl;
    alt_obj_calc.setX(77);
    alt_obj_calc.setY(8);
    cout << "Valorea lui x:" << alt_obj_calc.getX() << endl;
    cout << "Valorea lui y:" << alt_obj_calc.getY() << endl;


    cout << "Cel mai mare numar al primului obiect este:" << obj_calc.cel_mai_mare_numar() << endl;
    cout << "Cel mai mare numar celui de-al doilea obiect este:" << alt_obj_calc.cel_mai_mare_numar() << endl;

    cout << "Suma x + y la primul obiect este:" << obj_calc.suma() << endl;
    cout << "Suma x + y la cel de-al doilea obiect este:" << alt_obj_calc.suma() << endl;

    obj_calc.functie_care_acceseaza_functia_privata();

    return 0;
}