// Seminar6-gr1037.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// cout -> de tip ostream
// cin  -> de tip istream
#include <iostream>
using namespace std;

/*
    Pentru clasa Culoare creați
    1. Constructor cu parametri, default, de copiere
    2. Operator de atribuire, afisare, comparatie

*/

class Culoare {
private:
    int rosu;
    int verde;
    int albastru;
    const int MIN_VALUE = 0;
    const int MAX_VALUE = 255;
    bool isValidValue(int newValue) {
        return ((newValue >= MIN_VALUE) && (newValue <= MAX_VALUE));
    }
    static int counter;

    // membru alocat dinamic
    char* nume;

public:

    Culoare() {
        rosu = 0;
        verde = 0;
        albastru = 0;
        counter++;
        nume = new char[5]; // [ "0", "0", "0", "0", "\n" ]
        strcpy(this->nume, "NONE");

    }
    Culoare(int rosu, int verde, int albastru, const char* nume) {
        this->rosu = rosu;
        this->verde = verde;
        this->albastru = albastru;
        counter++;

        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        
    }

    // Culoare c1;
    // Culoare c2 = c1;
    Culoare(const Culoare &other) {
        this->rosu = other.rosu;
        this->verde = other.verde;
        this->albastru = other.albastru;
        counter++;

        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
    }

    // Culoare c1;
    // Culoare c2;
    // c1 = c2;
    // c1.operator(c2)
    Culoare& operator= (const Culoare& other) {
        this->rosu = other.rosu;
        this->verde = other.verde;
        this->albastru = other.albastru;

        return *this;
    }

    // Destructor -> 1 singur 
    ~Culoare() {
        counter--;
        // Sunt sterse valorile alocate dinamic
        delete[] nume;
    }

    // Culoare c1;
    // Culoare c2;
    // c1 == c2;
    // c1.operator(c2)
    bool operator== (const Culoare& other) {
        return (this->rosu == other.rosu) && (this->verde == other.verde) && (this->albastru == other.albastru);
    }

    int getRosu() {
        return rosu;
    }
    void setRosu(int newValue) {
        if (isValidValue(newValue))
            rosu = newValue;
    }
    int getAlbastru() {
        return albastru;
    }
    void setAlbastru(int newValue) {
        if (isValidValue(newValue))
            albastru = newValue;
    }
    int getVerde() {
        return verde;
    }
    void setVerde(int newValue) {
        if (isValidValue(newValue))
            verde = newValue;
    }

     // cout << obiect
     // Echivalent cout.operator<<(obiect)
    // Obiectul se poate inlantui              
    //       cout << obiect << altobiect
    //       (cout << obiect) << altobiect    
    //              | |
    //               V
    //             cout      << altobiect              

    friend ostream& operator<<(ostream& printer, Culoare& obiectCuloare){

        // As putea accesa valorile prin getter si setter -> atunci nu mai am nevoie de "friend"
        // printer << "(" << obiectCuloare.getRosu() << "," << obiectCuloare.getVerde() << "," << obiectCuloare.getAlbastru() << ")" << endl;

        printer << "(" << obiectCuloare.rosu << "," << obiectCuloare.verde << "," << obiectCuloare.albastru << ")" << endl;

        return printer;
    }

};


int Culoare::counter = 0;



int main()
{

    Culoare negru;
    Culoare fucshia(200, 34, 12, "fucshia");

    // operator << 
    cout << negru;

    Culoare alt_negru = negru;
    cout << alt_negru;

    cout << (alt_negru == negru);
  
}


