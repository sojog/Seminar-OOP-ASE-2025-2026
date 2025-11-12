#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



/*
    Pentru clasa Angajat creați
    1. Constructor de copiere
    2. Operator de atribuire, afisare, comparatie
*/

class Angajat {
    int varsta;
    double salariu;
    // atribut alocat dinamic (pointer)
    char* nume;

    // 
    int* zileDeConcediu;
    int nrZile;

public:
    // Constructor cu parametri
    Angajat(const char* nume, int varsta, double salariu, int* concediu, int nrZile) : varsta(varsta), salariu(salariu) {

        // Merge doar la char
        // pentru atribut alocat dinamic
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->zileDeConcediu = new int[nrZile];
        this->nrZile = nrZile;
        for (int i = 0; i < nrZile; i++) {
            zileDeConcediu[i] = concediu[i];
        }


    }

    // Constructor de copiere
    Angajat(const Angajat& a) {
        this->varsta = a.varsta;
        this->salariu = a.salariu;

        this->nume = new char[strlen(a.nume) + 1];
        strcpy(this->nume, a.nume);


        this->zileDeConcediu = new int[a.nrZile];
        for (int i = 0; i < nrZile; i++) {
            zileDeConcediu[i] = a.zileDeConcediu[i];
        }

    }
    // Clasa obiect1
    // Clasa obiect2
    // obiect2 = obiect1
    Angajat& operator= (const Angajat& from) {
        this->salariu = from.salariu;
        this->varsta = from.varsta;
        

        this->nume = new char[strlen(from.nume) + 1];
        strcpy(this->nume, from.nume);
        
        

        this->zileDeConcediu = new int[from.nrZile];
        for (int i = 0; i < nrZile; i++) {
            zileDeConcediu[i] = from.zileDeConcediu[i];
        }

        return *this;
    }
    // Destructor
    ~Angajat() {
        // daca este vorba de array folosesc 
        delete[] this->nume;

        // 
        delete[] this->zileDeConcediu;
    }

    bool operator== (const Angajat& compared) {
        return this->salariu == compared.salariu;
    }
    // a3 > a2
    bool operator> (const Angajat& compared) {
        return this->salariu > compared.salariu;
    }
    bool operator< (const Angajat& compared) {
        return this->salariu < compared.salariu;
    }

    // operator de afisare
    // cout << obiect << altceva
    friend ostream& operator<< (ostream& out, const Angajat& a) {
        out << "Salariatul cu varsta " << a.varsta << " si salariul " << a.salariu << endl;
        return out;
    }

    operator int() {
        return varsta;
    }

    operator double() {
        return salariu;
    }

    
    // ++obiect
    void operator++() {
        this->salariu += 1000;
    }
    // obiect++
    void operator++(int) {
        this->salariu += 2000;
    }

    // obiect += 132
    // obiect = obiect + 132
    Angajat&  operator+= (int valoare) {
        this->salariu += valoare;

        return *this;
    }
};

int main()
{
    Angajat a1("Ionut", 20, 30000);
    cout << a1;


    Angajat a2("Maria", 19, 29000);
    cout << a2;

    //a2 = a1;
    //cout << a2;

    Angajat a3("Florin", 29, 30000);
    cout << "Cei doi salariati au salariul egal: " << (a3 == a1) << endl;
    cout << "Cei doi salariati au salariul egal: " << (a3 == a2) << endl;

    cout << "Salariul lui a3 este mai mare ca a2? " << (a3 > a2) << endl;
    cout << "Salariul lui a3 este mai mic ca a2? " << (a3 < a2) << endl;


    int valoare = a3;
    cout << valoare << endl;

    int varsta_a1 = a1;
    cout << "varsta a1:" << varsta_a1 << endl;

    double salariu_a1 = a1;
    cout << "Salariul lui a1" << salariu_a1 << endl;

    ++a1;
    salariu_a1 = a1;
    cout << "Salariul lui a1" << salariu_a1 << endl;

    a1++;
    salariu_a1 = a1;
    cout << "Salariul lui a1" << salariu_a1 << endl;

    a1 += 4000;
    salariu_a1 = a1;
    cout << "Salariul lui a1" << salariu_a1 << endl;

}

