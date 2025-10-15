// Seminar3-1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>    // aici nu trebuie ;
using namespace std;  // aici trebuie ;

// TODO:  - setter pentru anul fabricatiei
// TODO: - folosirea lui in main

// CLASA - sablon pt creare de obiecte
// Conventie - incepe cu litera mare
class Calculator {
private:
    // notare de tip camelCase
    int spatiuStocare; // Varianta preferata (C++)
    // notare de tip snake_case
    int anul_fabricatiei;  // Varianta folosita in Python 


public:
    // CONSTRUCTOR - metoda speciala pentru initializare atributelor
    // De obicei el se afla in public!!!!

    Calculator() { // constructor fara parametri  (default)
        cout << "Constructorul clasei...." << endl;
        this->anul_fabricatiei = 2024;
        this->spatiuStocare = 128;
    }

    Calculator(int spatiuStocare) { // constructor cu 1 singur parametru
        cout << "Constructorul clasei...." << endl;
        this->anul_fabricatiei = 2019;
        this->spatiuStocare = spatiuStocare;
    }

    // Constructor cu parametri 
    Calculator(int an, int spatiu) {
        cout << "Constructorul clasei...." << endl;
        this->anul_fabricatiei = an;
        this->spatiuStocare = spatiu;
    }


    // GETTER - o functie (metoda) care citeste o valoare dintr-un atribut private
    int getSpatiuStocare() {
        return this->spatiuStocare;
    }

 

    // SETTER - o functie (metoda) care seteaza o valoare unui atribut private
    void setSpatiuStocare(int noulSpatiu) {
        if (noulSpatiu > 128) {
            spatiuStocare = noulSpatiu;
        }
    /*    else {
            spatiuStocare = 128;
        }*/
    }

    int getAnulFabricatiei() {
        return anul_fabricatiei;
    }

}; // aici se termina clasa (cu ";"  la final)



int main()
{   

    int x = 2;
    x = x;
    cout << "x=" << x << endl;

    // CONVENTIE numele de obiecte se scriu cu litera mica
    Calculator robot; // constructorul default -  Calculator()
    Calculator zalman(2016, 1000); // Calculator(int an, int spatiu)
    Calculator stefanCelMare(2000); //  Calculator(int spatiu)

    // VARIABILELE private nu pot fi accesate in afara clasei
    //robot.spatiuStocare = 500;
    robot.setSpatiuStocare(500);

    //zalman.spatiuStocare = 1;
    zalman.setSpatiuStocare(1);

    //stefanCelMare.spatiuStocare = -20;
    stefanCelMare.setSpatiuStocare(-20);

    cout << "Calculatorul ROBOT are spatiul de stocare: " << robot.getSpatiuStocare() << " GB" << endl;
    cout << "Calculatorul ZALMAN are spatiul de stocare: " << zalman.getSpatiuStocare() << " GB" << endl;
    cout << "Calculatorul StefanCelMare are spatiul de stocare: " << stefanCelMare.getSpatiuStocare() << " GB" << endl;


    cout << "Calculator ROBOT fabricat in " << robot.getAnulFabricatiei() << endl;
    cout << "Calculator ZALMAN fabricat in " << zalman.getAnulFabricatiei() << endl;
    cout << "Calculator StefanCelMare fabricat in " << stefanCelMare.getAnulFabricatiei() << endl;





}

