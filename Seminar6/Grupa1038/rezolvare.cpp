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
    // CONVENTIE Variabila consta cu litere mari (toate)
    const int PUTERE_MAXIMA = 1000;

    bool isValidPutere(int p) const {
        return p >= 0 && p <= PUTERE_MAXIMA; 
    }

    static int nr_masini;

    // Element alocat dinamic
    char* nume; 
public:
    Masina() {
        this->putereCP = 0;
        this->anFabricatie = 2025;
        nr_masini++;

        // char* nume; 
        // cout << "Margareta";
        nume = new char[10];                                  // Alocare ->  [ _, _ ,  _          ...         _  ]
        strcpy (nume, "Margareta");// lungimea sirului + "\0";

    }
    Masina(int putereCP, int anFabricatie, const char* nume) {
        this->putereCP = putereCP;
        this->anFabricatie = anFabricatie;

        nume = new char[strlen(nume) + 1];                                  // Alocare ->  [ _, _ ,  _          ...         _  ]
        strcpy(this->nume, nume);// lungimea sirului + "\0";

        ++nr_masini;
    }
    Masina(const Masina& other) {
        this->putereCP = other.putereCP;
        this->anFabricatie = other.anFabricatie;
        ++nr_masini;

        nume = new char[strlen(other.nume) + 1];                                  // Alocare ->  [ _, _ ,  _          ...         _  ]
        strcpy(this->nume, other.nume);// lungimea sirului + "\0";
    }

    // Destructor -> are ~ in fata
    // numele la fel ca la constructor fara param
    ~Masina() {
        cout << "Destructorul a fost apelat " << endl;
        --nr_masini;

        delete[]nume;
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
// Definirea valoarii initiale
int Masina::nr_masini = 0;


int main()
{
    // Constructor Default
    Masina m1;
    // Constructor cu parametri
    Masina m2(100, 2020, "Furia Rosie");
    // Constructor de copiere
    Masina m3 = m2;

    cout << m2;

    // Operator de comparare
    cout << (m3 == m2) << endl;

    // Operator de atribuire
    m1 = m3;

    cout << m1;

}
