// Creați clasa Sportiv care conține un nume, prenume și data nasterii.
#include <iostream>

using namespace std;

// clasa de baza
class Sportiv {
private: // accesibil din interiorul clasei
    string nume;
    string prenume;
protected: // accesibil din clasa mostenita sau din interiorul clasei
    int an;
    int zi;
    int luna;
public: // accesibil din exterior, din clasa mostenita sau din interiorul clasei
    string echipament;
};

// clasa derivata public - CEA MAI INTALNITA
class SportivDeEchipaPUBLIC : public Sportiv {
    string echipa;
public:
    void acceseazaAtributele(){
        cout <<  "Echipament (public) : " <<  this->echipament << endl ;
        cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume; inaccesibil
    }
};

class DUPLUSportivDeEchipaPUBLIC : public SportivDeEchipaPUBLIC {
    string echipa;
public:
    void acceseazaAtributele(){
        cout <<  "Echipament (public) : " <<  this->echipament << endl ;
        cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume; inaccesibil
    }
};


// clasa derivata protected
class SportivDeEchipaPROTECTED : protected Sportiv {
    string echipa;
public:
    void acceseazaAtributele(){
       cout <<  "Echipament (public) : " <<  this->echipament << endl ;
        cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume;  -> inaccesibil
    }
};

class DUBLUSportivDeEchipaPROTECTED : protected SportivDeEchipaPROTECTED {
    string echipa;
public:
    void acceseazaAtributele(){
       cout <<  "Echipament (public) : " <<  this->echipament << endl ;
        cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume;  -> inaccesibil
    }
};

// // clasa derivata private
class SportivDeEchipaPRIVATE : private Sportiv {
    string echipa;
public:
    void acceseazaAtributele(){
          cout <<  "Echipament (public) : " <<  this->echipament << endl ;
        cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume; -> inaccesibil
    }
};

// // clasa derivata private
class DUBLUSportivDeEchipaPRIVATE : private SportivDeEchipaPRIVATE {
    string echipa;
public:
    void acceseazaAtributele(){
        //   cout <<  "Echipament (public) : " <<  this->echipament << endl ; -> nu mai poate fi accesata
        // cout << "An (protected): " << this->an << endl ;
        // cout << "Nume (private): " << this->nume; -> inaccesibil
    }
};

int main (){
    DUPLUSportivDeEchipaPUBLIC obj_mostenire_publica;
    obj_mostenire_publica.acceseazaAtributele();

    DUBLUSportivDeEchipaPROTECTED obj_mostenire_protected;
    obj_mostenire_protected.acceseazaAtributele();

    DUBLUSportivDeEchipaPRIVATE obj_mostenire_private;
    obj_mostenire_private.acceseazaAtributele();
}
