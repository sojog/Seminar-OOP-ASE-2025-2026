
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
public:
    // Constructor cu parametri
    Angajat(int varsta, double salariu) : varsta(varsta), salariu(salariu) {
    }

    // Constructor de copiere
    Angajat(const Angajat& a) {
        this->varsta = a.varsta;
        this->salariu = a.salariu;

    }
    // Clasa obiect1
    // Clasa obiect2
    // obiect2 = obiect1
    Angajat& operator= (const Angajat& from) {
        this->salariu = from.salariu;
        this->varsta = from.varsta;
        return *this;
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
    Angajat a1(20, 30000);
    cout << a1;


    Angajat a2(19, 29000);
    cout << a2;

    //a2 = a1;
    //cout << a2;

    Angajat a3(29, 30000);
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

