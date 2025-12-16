// Creați clasa Sportiv care conține un nume, prenume și data nasterii.
#include <iostream>
#include <fstream>   // fstream este mostenit din ostream
// fstream = ofstream + ifstream
using namespace std;

// clasa de baza
class Sportiv {

private: // accesibil din interiorul clasei
    int counter;

protected: // accesibil din clasa mostenita sau din interiorul clasei
    string nume;
    string prenume;
    int an;
    int zi;
    int luna;

public: // accesibil din exterior, din clasa mostenita sau din interiorul clasei
    string echipament;


    // Constructor poate fi doar 1
    Sportiv(string nume, string prenume, int an, int zi, int luna): nume(nume), prenume(prenume), an(an), zi(zi), luna(luna){     
    }
    // cout << obj
    friend ostream& operator<< (ostream& console, Sportiv& obj ){
        console << obj.nume << " " << obj.prenume << " nascut pe " << obj.zi << "-" << obj.luna << "-" << obj.an << endl;
        return console;
    }
};

// clasa derivata 
class SportivDeEchipa : public Sportiv {
    string echipa;
public:

    SportivDeEchipa(string echipa, string nume, string prenume, int an, int zi, int luna): Sportiv(nume, prenume, an, zi, luna) {
        this->echipa = echipa;
    }

      friend ostream& operator<< (ostream& console, SportivDeEchipa& obj ){
        // nume si prenume -> daca sunt private nu sunt accesibile in clasa derivata
        console << obj.nume << " " << obj.prenume << " nascut pe " << obj.zi << "-" << obj.luna << "-" << obj.an << endl << "joaca la " << obj.echipa;
        return console;
    }


};

int main (){
    Sportiv sp1("Ionescu", "Ion", 2000, 5, 12);
    // cout este de tip ostream
    cout << sp1;

    // atributul echipament este public
    sp1.echipament = "rosu/negru";
    cout << "Echipamentul sportivului  " << sp1.echipament;



}
