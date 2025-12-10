// Seminar8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*

Creați o clasă ParcarePublica care să contorizez numărul de mașini dintr-o parcare și duratele de parcare.
Parcarea are o taxă de parcare, precum și o capacitate maximă de mașini.

1. Implementați clasa cu 1 membru alocat dinamic, unul constant și unul static.

2. Creați cpnstructori și destructor

3. Operatorii <<, ++
*/

class ParcarePublica {
private:
    int nrMasini;
    int* durataParcare;
    const int capacitate;
public:
    static float taxa;
    ParcarePublica() :capacitate(50)
    {
        this->nrMasini = 0;
        this->durataParcare = nullptr;

    }
    ParcarePublica(int nrMasini, int* durataParcare, int capacitate) :
        nrMasini(nrMasini), capacitate(capacitate) {
        this->durataParcare = new int[nrMasini];
        for (int i = 0; i < nrMasini; i++)
            this->durataParcare[i] = durataParcare[i];
    }
    int getNrMasini() {
        return this->nrMasini;
    }

    friend ostream& operator<< ( ostream& out,  const ParcarePublica &p)
    {
        out << "nrMasini:" << p.nrMasini << endl;
        out << "durataParcare:" << p.durataParcare << endl;
        out << "";
            for (int i = 0; i < p.nrMasini; i++) { 
                out << "nr masini care incap " << p.nrMasini << endl;


            }
            return out;

       
    }

    ParcarePublica operator++ () {
        this->nrMasini += 1;
        /*TODO: DURATE PARCARE*/
        /*this->durataParcare += 1;*/
        return *this;
    }
    
};

int main()
{
    ParcarePublica p;
    cout << p.getNrMasini() << endl;
}
