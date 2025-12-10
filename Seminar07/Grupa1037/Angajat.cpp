#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

/*
    Pentru clasa Angajat:
    1. Constructor de copiere
    2. Operator de atribuire, afișare, comparație
    3. Conversii implicite, operatori ++, += etc.
*/

class Angajat {
    int varsta;
    double salariu;
    char* nume;
    int* zileDeConcediu;
    int nrZile;

public:
    // Constructor cu parametri
    Angajat(const char* nume, int varsta, double salariu, int* concediu, int nrZile)
        : varsta(varsta), salariu(salariu), nrZile(nrZile)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        this->zileDeConcediu = new int[nrZile];
        for (int i = 0; i < nrZile; i++) {
            this->zileDeConcediu[i] = concediu[i];
        }
    }

    // Constructor de copiere
    Angajat(const Angajat& a)
        : varsta(a.varsta), salariu(a.salariu), nrZile(a.nrZile)
    {
        nume = new char[strlen(a.nume) + 1];
        strcpy(nume, a.nume);

        zileDeConcediu = new int[nrZile];
        for (int i = 0; i < nrZile; i++) {
            zileDeConcediu[i] = a.zileDeConcediu[i];
        }
    }

    // Operator de atribuire (regula celor 3/5)
    Angajat& operator=(const Angajat& from) {
        if (this == &from) return *this;  // anti auto-atribuire

        // Eliberăm memoria veche
        delete[] nume;
        delete[] zileDeConcediu;

        // Copiem datele
        varsta = from.varsta;
        salariu = from.salariu;
        nrZile = from.nrZile;

        nume = new char[strlen(from.nume) + 1];
        strcpy(nume, from.nume);

        zileDeConcediu = new int[nrZile];
        for (int i = 0; i < nrZile; i++) {
            zileDeConcediu[i] = from.zileDeConcediu[i];
        }

        return *this;
    }

    // Destructor
    ~Angajat() {
        delete[] nume;
        delete[] zileDeConcediu;
    }

    // Operatori de comparație
    bool operator==(const Angajat& compared) const {
        return this->salariu == compared.salariu;
    }

    bool operator>(const Angajat& compared) const {
        return this->salariu > compared.salariu;
    }

    bool operator<(const Angajat& compared) const {
        return this->salariu < compared.salariu;
    }

    // Operator de afișare
    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out << "Salariatul \"" << a.nume << "\" are varsta " << a.varsta
            << " si salariul " << a.salariu << " RON";
        return out;
    }

    // Conversii implicite
    operator int() const {
        return varsta;
    }

    operator double() const {
        return salariu;
    }

    // ++obiect (pre-increment)
    Angajat& operator++() {
        this->salariu += 1000;
        return *this;
    }

    // obiect++ (post-increment)
    Angajat operator++(int) {
        Angajat temp = *this;
        this->salariu += 2000;
        return temp;
    }

    // obiect += valoare
    Angajat& operator+=(int valoare) {
        this->salariu += valoare;
        return *this;
    }

    // Getter pentru testare (opțional)
    const char* getNume() const { return nume; }
    double getSalariu() const { return salariu; }
};

int main()
{
    // Date pentru zile de concediu
    int concediu1[] = { 2, 1, 0, 3, 1 };  // 5 zile
    int concediu2[] = { 1, 1, 1, 0, 2 };
    int concediu3[] = { 3, 2, 1, 1, 0 };

    Angajat a1("Ionut", 20, 30000, concediu1, 5);
    cout << a1 << endl;

    Angajat a2("Maria", 19, 29000, concediu2, 5);
    cout << a2 << endl;

    // Testare atribuire
    Angajat a4("Temp", 25, 1000, concediu3, 5);  // obiect temporar
    a4 = a1;  // atribuire
    cout << "Dupa atribuire, a4: " << a4 << endl;

    Angajat a3("Florin", 29, 30000, concediu3, 5);
    cout << "Cei doi salariati au salariul egal (a3 == a1): " << (a3 == a1) << endl;
    cout << "Cei doi salariati au salariul egal (a3 == a2): " << (a3 == a2) << endl;
    cout << "Salariul lui a3 este mai mare ca a2? " << (a3 > a2) << endl;
    cout << "Salariul lui a3 este mai mic ca a2? " << (a3 < a2) << endl;

    // Conversii implicite
    int varsta = a3;
    cout << "Varsta lui a3 (conversie): " << varsta << endl;

    int varsta_a1 = a1;
    cout << "Varsta a1: " << varsta_a1 << endl;

    double salariu_a1 = a1;
    cout << "Salariul lui a1 (conversie): " << salariu_a1 << endl;

    // ++a1
    ++a1;
    salariu_a1 = a1;
    cout << "Salariul lui a1 dupa ++a1: " << salariu_a1 << endl;

    // a1++
    a1++;
    salariu_a1 = a1;
    cout << "Salariul lui a1 dupa a1++: " << salariu_a1 << endl;

    // a1 += 4000
    a1 += 4000;
    salariu_a1 = a1;
    cout << "Salariul lui a1 dupa a1 += 4000: " << salariu_a1 << endl;

    return 0;
}