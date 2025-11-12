#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
    Pentru clasa Apartament creați
    1. Constructor de copiere
    2. Operator de atribuire, afisare, comparatie

    3. Adaugati un membru alocat dinamic preturiDeVanzare pentru preturile cu care a fost vandut apartamentul
*/

class Apartament {
    double pret;
    int suprafata;

    // Pointer -> obiect alocat dinamic
    char* strada;

    double *preturiDeVanzare;
    int nrPreturi;
public:
    // Constructor cu parametri
    Apartament(const char* strada, int suprafata, double pret, double* preturiDeVanzare, int nrPreturi) : suprafata(suprafata), pret(pret) {

        this->strada = new char[strlen(strada) + 1]; // strlen -> functioneaza doar pt char/stringuri
        strcpy(this->strada, strada);

        this-> nrPreturi = nrPreturi;
        this->preturiDeVanzare = new double[nrPreturi];
        for (int i = 0; i < nrPreturi; i++) {
            this->preturiDeVanzare[i] = preturiDeVanzare[i];
        }

    }

    // Constructor de copiere
    // Clasa obiect1;
    // Clasa obiect2 = obiect;
    Apartament(const Apartament& other) {
        this->suprafata = other.suprafata;
        this->pret = other.pret;

        this->strada = new char[strlen(other.strada) + 1]; // strlen -> functioneaza doar pt char/stringuri
        strcpy(this->strada, other.strada);

        this->nrPreturi = other.nrPreturi;
        this->preturiDeVanzare = new double[other.nrPreturi];
        for (int i = 0; i < other.nrPreturi; i++) {
            this->preturiDeVanzare[i] = preturiDeVanzare[i];
        }


    }

    // Operator de atribuire
    Apartament& operator=(const Apartament& other) {
        if (this == &other) {
            return *this;
        }

        // !!!! O sterg pe cea care exista deja
        delete[] this->strada;

        delete[] this->preturiDeVanzare;

        this->nrPreturi = other.nrPreturi;
        this->preturiDeVanzare = new double[other.nrPreturi];
        for (int i = 0; i < other.nrPreturi; i++) {
            this->preturiDeVanzare[i] = preturiDeVanzare[i];
        }


        this->strada = new char[strlen(other.strada) + 1]; // strlen -> functioneaza doar pt char/stringuri
        strcpy(this->strada, other.strada);

        this->suprafata = other.suprafata;
        this->pret = other.pret;
        return *this;
    }

    ~Apartament() {

        // delete [] -> pt array/vector
        delete[] strada;

        delete[] preturiDeVanzare;
    }


    // operator de afisare
    // cout << obiect
    friend ostream& operator<< (ostream& consola, const Apartament& apart) {
        consola << "Apartamentul are: " << apart.suprafata << " mp si costa: " << apart.pret << " EURO" << endl;
        return consola;
    }
    // Operator de comparatie
    bool operator== (const Apartament& other) {
        return this->pret == other.pret;
    }
    // obiect1 < obiect2
    bool operator<  (const Apartament& other) {
        return this->pret < other.pret;
    }
    bool operator>  (const Apartament& other) {
        return this->pret > other.pret;
    }

    operator int() {
        return this->suprafata;
    }

    operator double() {
        return this->pret;
    }

    // ++obiect
    Apartament& operator++() {
        this->pret += 1000;
        return *this;
    }

    // obiect ++ valoare
    Apartament& operator++(int) {
        this->pret += 2000;
        return *this;
    }
    // obiect += 300
    // obiect = obiect + 300
    Apartament& operator+= (int suma) {
        this->pret += suma;
        return *this;
    }

    // --obiect
    Apartament& operator--() {
        this->pret -= 1000;
        return *this;
    }


};
int main()
{
    Apartament ap1("Universitate", 40, 80000);
    Apartament ap2 = ap1; // constructor de copiere

    cout << ap2;

    Apartament ap3("Carol", 50, 80000);
    Apartament ap4("Victoriei", 40, 90000);
    cout << "Sunt egale (pret) cele doua apartamente: " << (ap1 == ap3) << endl;
    cout << "Sunt egale (pret) cele doua apartamente: " << (ap1 == ap4) << endl;

    cout << "Primul ap este mai ieftin ca al doilea " << (ap1 < ap4) << endl;
    cout << "Primul ap este mai scump ca al doilea " << (ap1 > ap4) << endl;

    int suprafa_ap4 = ap4;
    cout << "Suprafata ap4: " << suprafa_ap4 << endl;

    double pret_ap4 = ap4;
    cout << "Pret ap4 " << pret_ap4 << endl;
    ++ap4;

    pret_ap4 = ap4;
    cout << "Pret ap4 " << pret_ap4 << endl;

    ap4++;
    pret_ap4 = ap4;
    cout << "Pret ap4 " << pret_ap4 << endl;

    ap4 += 222;
    cout << ap4;

}
