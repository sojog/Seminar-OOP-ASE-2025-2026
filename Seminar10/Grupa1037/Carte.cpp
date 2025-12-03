// Seminar10-1037.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



class Autor {
    char* nume;
public:
    Autor(const char* nume = "Anonim") {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }
    ~Autor() {
        delete[] nume;
    }
    friend ostream& operator<<(ostream& out, Autor& obj) {
        out << obj.nume << endl;
        return out;
    }
};
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
//          NU EXISTA RELATIE DE TIPU "IS A" INTRE CARTE SI AUTOR
// 
//                  PT CA NU ARE SENS (cartea nu este autor, si autorul nu este carte)
// 
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Carte -> Autor (Has a) -> are un autor


class Carte {
    char* titlu;
    Autor* autor;
public:
    Carte(const char* nume = "Anonim", Autor* autor = new Autor()) {
        this->titlu = new char[strlen(nume) + 1];
        strcpy_s(this->titlu, strlen(nume) + 1, nume);

        this->autor = autor;
    }
    ~Carte() {
        delete[] titlu;
        delete autor;
    }
    friend ostream& operator<<(ostream& out, Carte& obj) {
        out << "Cartea '" << obj.titlu << "' scrisa de:" << *obj.autor << endl;
        return out;
    }
};

// Carte este clasa de baza
// Roman este clasa derivata
class Roman : public Carte {
    string tip;
public:
    Roman(const char* nume = "Anonim", Autor* autor = new Autor(), string tip = "interbelic") : Carte(nume, autor) {
        this->tip = tip;
    }

    friend ostream& operator<<(ostream& out, Roman& obj) {
        out << "Romanul de tip: " << obj.tip << endl;
        return out;
    }
};


// TODO: creati o clasa Manual care sa contina clasa pentru care este facuta (ex: a7a, a8a)



int main()
{
    Autor autor1; // obiectul
    cout << autor1;

    Autor* autor2 = new Autor("Marcus Aurelius");
    cout << *autor2; // autor2 -> este pointer

    Carte* carte1 = new Carte("Ganduri catre sine", autor2);
    cout << *carte1;

    Roman roman1;
    cout << roman1;

    Autor* autor3 = new Autor("Jane Austin");

    Roman *roman2 = new Roman("Mandrie si prejudecata", autor3, "antebelic");
    cout << *roman2;
}
