// Seminar3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// EXTERIORUL CLASEI

#include <iostream>  // - nu e nevoie de ;
using namespace std; // - e nevoie de ;

// Vreau sa treceti cai_putere in PRIVATE;
// Vreau sa faceti un GETTER pentru cai_putere;
// Vreau sa folositi GETTER-ul in main


// conventie - numele clasei cu litera mare!!!
class Masina {
// INTERIOR CLASA - inceput
// 
// by default toate elemente sunt private - daca nu sunt specificat in alt mod!!!
private:
    // denumirile cu litera mica (camelCase) - preferat in C++
    int anulFabricatiei;
    // denumire cu litera mica (snake_case) - preferat in Python
    int cai_putere;

public:
    


    // CONSTRUCTOR - functie speciala (nu intoarce nimic)
    // se afla de obicei in PUBLIC
    // CONSTRUCTOR fara parametri sau IMPLICIT
    Masina() {
        anulFabricatiei = 1901;
        cai_putere = 80;
    }

    // CONSTRUCTOR CU PARAMETRI
    Masina(int an, int cai) {
        this->anulFabricatiei = an;
        this->cai_putere = cai;

    }
  
    // Constructor cu 1 singur parametru
    Masina(int anulFabricatiei) {
        // this  -> este POINTER catre obiectul curent
        this->anulFabricatiei = anulFabricatiei;
        cai_putere = 80;
    }

    // GETTER
    int getAnulFabricatiei() {
        return anulFabricatiei;
    }

    // SETTER 
    void setAnulFabricatiei(int noulAn) {
        // imi permite sa fac verificarile necesare
        if ((noulAn > 1900) && (noulAn <= 2025)) {
            anulFabricatiei = noulAn;
        }
    }

    int getCaiPutere() {
        return this->cai_putere;
    }

    void setCaiPutere(int caiPutere) {
        this->cai_putere = caiPutere;
    }


    // INTERIOR CLASA - sfarsit
    // 
}; // AICI se termina clasa

// EXTERIORUL CLASEI


int main()
{        

    // EXTERIORUL CLASEI  - nu pot accesa elementele private
    std::cout << "Hello World!\n";

    

    // obiect - instanta (concretizare)
    Masina margareta; // constructor fara parametri
    Masina ursulet(2003); // constructor cu 1 singur parametru
    Masina madalina(2015, 112); // constructor cu toti parametri

    // Nu se poate accesa fiindca este PRIVATE
    //margareta.anulFabricatiei = 1991;

    margareta.setAnulFabricatiei(1991);
    margareta.setCaiPutere(200);
    margareta.setAnulFabricatiei(300);
    cout << "Anul fabricatiei masinii Margareta " << margareta.getAnulFabricatiei() << endl;
    cout << "Anul fabricatiei masinii URSULET " << ursulet.getAnulFabricatiei() << endl;
    cout << "Anul fabricatiei masinii MADALINA " << madalina.getAnulFabricatiei() << endl;




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
