// Seminar4-1037.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

1. Creați o clasă "Factură" cu 1 parametru "valoare".
2. Creați getter și setter pentru "valoare".
3. Creați câte un constructor cu parametru și fără.
*/


#include <iostream>
using namespace std;


class Factura {
private:
    int valoare;
     const int nr_factura;
public:
    // static - este o valoare la nivel de clasa
    static int counter;

    // static - caz clasic TVA
    static int tva;

    // constructor fara parametri 
    // Pentru valori constante -> parametri trebuie sa fie trecuti inline
    Factura(): nr_factura(++counter){
        this->valoare = 0;
        //this->nr_factura = counter++;
        //this->nr_factura = 3000;
    }
    Factura(int valoare) : nr_factura(++counter), valoare(valoare){
        //this->valoare = valoare;
        //this->nr_factura = counter++;
    }

    // constructor de copiere
    // obiectul1 = obiectul2;
    // int x = 20;
    // int y = x;
     Factura(const Factura& factura_de_copiat): nr_factura(++counter), valoare(factura_de_copiat.valoare) {
        //this->valoare = factura_de_copiat.valoare;
        //this->nr_factura = ++counter;
    }


    int getValoare() {
        return this->valoare;
    }
    float getValoareCuTVA() {

        return this->valoare + this->valoare * Factura::tva / 100;
    }
    void setValoare(int valoare) {
        this->valoare = valoare;
    }
    int getNumarFactura() {
        return this->nr_factura;
    }

};

int Factura::counter = 0;
int Factura::tva = 21;

int main()
{   
    // Variabila statica
    cout << "Factura::tva" << Factura::tva << endl;
    
    // Cate obiecte sunt create, adica valoarea counter-ului
    cout << "Factura::counter" << Factura::counter << endl;

    // Constructor fara parametri
    Factura fact1;
    cout << "Factura cu nr" << fact1.getNumarFactura() << "are valoarea: " << fact1.getValoare() << " cu tva" << fact1.getValoareCuTVA() << endl;

    // Constructor cu parametri
    Factura fact2(123);
    cout << "Factura cu nr" << fact2.getNumarFactura() << " are valoarea: " << fact2.getValoare() << " cu tva" << fact2.getValoareCuTVA() << endl;

    // Cate obiecte sunt create, adica valoarea counter-ului
    cout << "Factura::counter" << Factura::counter << endl;

    Factura fact_copiata = fact2;
    cout << "Factura copiata are valoarea " << fact_copiata.getValoare() << "are numarul de factura" << fact_copiata.getNumarFactura() << endl;

}

