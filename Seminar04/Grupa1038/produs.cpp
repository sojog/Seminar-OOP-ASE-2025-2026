// Seminar4-grupa1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
1. Creați o clasă "Produs" cu 1 parametru "pret".
2. Creați getter și setter pentru "pret".
3. Creați câte un constructor cu parametru și fără.
4. Creați 2 obiecte în main cu fiecare constructor.
*/

#include <iostream>
using namespace std;

class Produs {
private:
    int pret;
    const int nr_ctr;

public:
    static int contor;
    static int TVA;

    // constructor fara parametri
    Produs() : nr_ctr(++contor), pret(0) {
        //pret = 0;
        //nr_ctr = ++contor;
    }

    // constructor cu parametri
    Produs(int pret) : nr_ctr(++contor),  pret(pret){
        //this->pret = pret;
        //nr_ctr = ++contor;

    }

    // constructor de copiere
    // Este folosit sub forma:    NumeClasa obiectCreat = obiectDinCareVoiCopia;
    Produs( const Produs &produs_de_copiat ) : nr_ctr(++contor) {
        this->pret = produs_de_copiat.pret;
        //this->nr_ctr = ++contor;
    }
    int getNumarProdus() {
        return this->nr_ctr;
    }
    int getPret() {
        return this->pret;
    }
    void setPret(int pret) {
        this->pret = pret;
    }
    int getPretCuTVA() {
        return this->pret + Produs::TVA * this->pret / 100;
    }

};

int Produs::contor = 0;
int Produs::TVA = 21;

int main() {
   
    
    cout << "Produse create: " << Produs::contor << endl;

    // constructor fara parametri
    Produs prod1, prod2(23);
    cout << "Produsul cu nr" << prod1.getNumarProdus() << " si  valoarea:" << prod1.getPret() << 
        "are pretul cu tva" << prod1.getPretCuTVA() << endl;
    cout << "Produsul cu nr" << prod2.getNumarProdus() << " si valoarea:" << prod2.getPret() <<
        "are pretul cu tva" << prod2.getPretCuTVA() << endl;
    cout << "Produse create: " << Produs::contor << endl;

    // Constructor de copiere
    Produs produsCopiat = prod2;
    cout << "Produsul copiat are nr" << produsCopiat.getNumarProdus() << " si valoarea: " << produsCopiat.getPret() << endl;
}


