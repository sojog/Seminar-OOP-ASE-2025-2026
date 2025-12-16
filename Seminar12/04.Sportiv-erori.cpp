#include <iostream>

using namespace std;

// clasa de baza
class SportivCuValoriDefault {
private: // accesibil din interiorul clasei
    string nume;
    string prenume;
protected: // accesibil din clasa mostenita sau din interiorul clasei
    unsigned int an;
    unsigned int zi;
    unsigned int luna;
public: // accesibil din exterior, din clasa mostenita sau din interiorul clasei
    string echipament;

     SportivCuValoriDefault(string nume, string prenume, int an, int zi, int luna): nume(nume), prenume(prenume){     
        // Verificarea valorilor
       
        // Mecanism 1 -> ii dau o valoare default
        if (an > 1900) {
            this->an = an;
        }
        else {
            this->an = 1900;
        }


        if (zi < 31) {
            this->zi = zi;
        }
        else {
            this->zi = 1;
        }
        if (luna < 13) {
            this->luna = luna;
        }
        else {
            this->luna = 1;
        }

    }

    friend ostream& operator<< (ostream& console, SportivCuValoriDefault& obj ){
        console << obj.nume << " " << obj.prenume << " nascut pe " << obj.zi << "-" << obj.luna << "-" << obj.an << endl;
        return console;
    }
};
 

class SportivCuEroare {
private: // accesibil din interiorul clasei
    string nume;
    string prenume;
protected: // accesibil din clasa mostenita sau din interiorul clasei
    unsigned int an;
    unsigned int zi;
    unsigned int luna;
public: // accesibil din exterior, din clasa mostenita sau din interiorul clasei
    string echipament;

     SportivCuEroare(string nume, string prenume, int an, int zi, int luna): nume(nume), prenume(prenume){     
        // Verificarea valorilor
       
        // Mecanism 1 -> ii dau o valoare default
        if (an > 1900) {
            this->an = an;
        }
        else {
            throw "Anul nu poate fi mai mic decat 1900";
        }


        if (zi < 31) {
            this->zi = zi;
        }
        else {
            throw 123;
        }
        if (luna < 13) {
            this->luna = luna;
        }
        else {
            throw 312;
        }

    }

    friend ostream& operator<< (ostream& console, SportivCuEroare& obj ){
        console << obj.nume << " " << obj.prenume << " nascut pe " << obj.zi << "-" << obj.luna << "-" << obj.an << endl;
        return console;
    }
};


int main(){

    // O sursa de eroare
    // int x = 10 / 0;
    // cout << x;

    // 
    // int valoare_citita;
    // cin >> valoare_citita;

    // cout << "Ai citit de la tastatura : " << valoare_citita << endl;

    SportivCuValoriDefault sp1("Florinescu", "Florin", 1933,  39, 13);
    cout << sp1;

    try
    {
          SportivCuEroare sp1("Florinescu", "Florin", 1833,  39, 13);
          cout << sp1;
    }
    catch(const exception& e)
    {
        cout << "A aparut o eroare" << endl;
        cerr << e.what() << '\n';
    }
    catch (const char* ex) {
        cout << "A aparut o eroare generica de tip string" << endl;
        cout << ex << endl;
    }
    
     catch (const int ex) {
        cout << "A aparut o eroare generica de tip int" << endl;
        cout << ex << endl;
    }

 
}