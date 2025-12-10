// Seminar5-grupa1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
Creați o clasă Coordonata care conțină
1. Parametri latitudine și longitudine care reprezintă coordinatele pe glob.
2. Getter și setter pentru coordonate
3. Constructor cu parametri
4. Constructor default
5. Creați 2 obiecte în main cu fiecare constructor.
5. Constructor de copiere
6. Creați un alt obiect in main folosind acest constructor
7. Un membru static și unul constant pentru clasa.
8. Creați o funcție care să calculeze distanța între aceste 2 coordonate.
*/

class Coordonata {
private:
    int latitudine, longitudine;
public:
    // Constructor default
    Coordonata() {
        latitudine = 0;
        longitudine = 0;
    }
    // Constructor cu parametri
    Coordonata(int latitudine, int longitudine) {
        this->latitudine = latitudine;
        this->longitudine = longitudine;
    }
    // Constructor de copier
    // ex:   Coordonata obiect1; -> obiect deja creat
    //       Coordonata obiect2 = obiect1; -> obiect se creaza acum cu acest constructor
    Coordonata(const Coordonata &obiectDeCopiat) {
        this->latitudine = obiectDeCopiat.latitudine;
        this->longitudine = obiectDeCopiat.longitudine;
    }
    // Operator de atribuire
    //  Coordonata obiect1; -> obiect deja creat
    // Coordonata obiect2;  -> obiect deja creat
    // obiect2 = obiect1 -> asa se foloseste

    void operator= (const Coordonata& obiectDeCopiat) {
        cout << "Operator de atribuire";
        this->latitudine = obiectDeCopiat.latitudine;
        this->longitudine = obiectDeCopiat.longitudine;
    }

    // Operator de comparatie
    // obiect1 == obiect2
    // obiect1.operatorEgal(obiect2)

    bool operator== (const Coordonata& obiectDeComparat) {
    
        if ((this->latitudine == obiectDeComparat.latitudine) &&
            (this->longitudine == obiectDeComparat.longitudine)) {
            return true;
       }
        else {
            return false;
        }
    }

    

    int getLatitudine() {
        return this->latitudine;
    }
    int getLongitudine() {
        return this->longitudine;
    }
    void setLatitudine(int latitudine) {
         this->latitudine = latitudine;
    }
    void getLongitudine(int longitudine) {
         this->longitudine = longitudine;
    }

    friend ostream& operator<<(ostream& consola, const Coordonata& obiectDePrintat);
};

// Operator de afisare
    // cout << obiect
    // cout.operator<<(obiect)
// cout << 10 << 20; -> (cout << 10) << 20 -> printeaza apoi returineaza cout << 20
ostream&  operator<<(ostream& consola, const Coordonata& obiectDePrintat) {

    consola << "(" << obiectDePrintat.latitudine << " , " << obiectDePrintat.longitudine << " )";

    return consola;
}

int main()
{
    Coordonata c0;
    Coordonata c1(45, 39);
    cout << "Coordonata c0 are valorile: " << c0.getLatitudine() << " , " << c0.getLongitudine() << endl;
    cout << "Coordonata c1 are valorile: " << c1.getLatitudine() << " , " << c1.getLongitudine() << endl;
    Coordonata c2 = c1;
    cout << "Coordonata c2 are valorile: " << c2.getLatitudine() << " , " << c2.getLongitudine() << endl;
    
    Coordonata c3;
    // operator de atribuire
    c3 = c2;

    // operator de comparatie
   cout << "Obiectele sunt egale? " <<  (c3 == c2) << endl;

   // operator de afisare
   cout << c3;

   //int a = 10;
    //int b =6;
    //b == a;
}

