// Seminar6-grupa1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // i -> input 0-> out
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
    Masina() {
        this->putereCP = 0;
        this->anFabricatie = 2025;
    }
    Masina(int putereCP, int anFabricatie) {
        this->putereCP = putereCP;
        this->anFabricatie = anFabricatie;
    }
    Masina(const Masina& other) {
        this->putereCP = other.putereCP;
        this->anFabricatie = other.anFabricatie;
    }


    // ---------- Getteri ----------
    int getPutereCP() { return putereCP; }
    int getAnFabricatie() { return anFabricatie; }


    // ---------- Setteri ----------
    void setPutereCP(int cp) {
        if (isValidPutere(cp))
            putereCP = cp;
    }
    void setAnFabricatie(int an) {
        anFabricatie = an;
    }

    //  cout << m2;
    //  obiect1 << obiect2
    //  obiect1.operator<<(obiect2)  -> operatorul este o functie


    //   cout << 2 << "hello" ;
    //  cout << m2 << m1;
    //  (cout << m2) << m1;
    //      | |
    //       V
    //      cout     << m1;


    //  obiect operator altceva
    //    cout operator obiect
    friend ostream& operator<< (ostream& imprimanta, Masina& masina) {

        // As putea sa accesez getteri si setteri direct, fara valorile private -> nu am nevoie de friend
        //cout << masina.getPutereCP() << " cai " << masina.getAnFabricatie() << " an" << endl;

        cout << masina.putereCP << " cai " << masina.anFabricatie << " an" << endl;
        return imprimanta;
    }

    // obiect1 == obiect2
    // ECHIVALENT cu obiect1.operator==(obiect2)
    bool operator==(Masina& other) {
       return (this->putereCP == other.putereCP) &&  (this->anFabricatie == other.anFabricatie);
    }
    
    // obiect1 = obiect2
    Masina& operator=(Masina& other) {
        this->putereCP = other.putereCP;
        this->anFabricatie = other.anFabricatie;
        return *this;
    }
};



int main()
{
    // Constructor Default
    Masina m1;
    // Constructor cu parametri
    Masina m2(100, 2020);
    // Constructor de copiere
    Masina m3 = m2;

    cout << m2;

    // Operator de comparare
    cout << (m3 == m2) << endl;

    // Operator de atribuire
    m1 = m3;

    cout << m1;

}
