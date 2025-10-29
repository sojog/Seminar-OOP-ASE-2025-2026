// Seminar5-grupa1037.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*

Creați o clasă Punct care conțină
1. Parametri x și y care reprezintă coordinatele punctului in spațiu 2D.
2. Getter și setter pentru puncte
3. Constructor cu parametri
4. Constructor default
5. Constructor de copiere
6. Un membru static și unul constant pentru clasa.
7. Creați 2 obiecte în main
8. Creați o funcție care să calculeze distanța între aceste 2 puncte.
*/


class Punct {
    int x, y;
public:
    Punct(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Punct() {
        this->x = 0;
        this->y = 0;
    }
    // Constructor de copiere -  Punct p3=p1;
    Punct(const Punct &other) {
        this->x = other.x;
        this->y = other.y;
    }
    // Operator de atribuire
    //Punct p5;
    //Punct p6;
    // p6 = p5;
    Punct&  operator= (const Punct& other) {
        this->x = other.x;
        this->y = other.y;

        return *this;
    }
    
    // Operator de comparatie
    // p3 == p1        -> 
    bool operator== (const Punct& other) {

        if ((this->x == other.x) && (this->y == other.y)) {
            return true;
        }
        else {
            return false;
        }

    }

    

    int getX() { 
        return this->x;
    }
    int getY() { 
        return this->y; 
    }
    void setX(int x) {  
        this->x = x; 
    }
    void setY(int y) { 
        this->y = y; 
    }

    void afiseazaCoordonatele() {
        cout << "(" << this->x << "," << this->y << ")";
    }

    // operator==
    // obiect1 == obiect2
    
    //cout << p3 << p5; 
    
   friend ostream& operator<< (ostream& out, const Punct& other);
};
ostream&  operator<< (ostream& out, const Punct& other)
{
    out << "(" << other.x << "," << other.y << ")";

    return out;
}
int main()
{   
    // Constructor cu 2 param
    Punct p1(10, 20);
    cout << "p1 are coord: " << p1.getX() << " si  " << p1.getY() << endl;
    // Constructor fara param
    Punct p2;
    // Constructor de copiere;
    Punct p3 = p1;

    int a = 10;
    int b = a;
    cout << "a==b? " << (a == b) << endl;

    bool sunt_egale = (p3 == p1);
    cout << "p3 == p1 " << sunt_egale << endl;

    p3.afiseazaCoordonatele();

    cout << "Operatorul de afisare:";
    cout << p3;
}
