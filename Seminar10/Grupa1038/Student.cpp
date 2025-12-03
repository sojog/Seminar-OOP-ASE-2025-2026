// Seminar10-grupa1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//
// Student
// Student -> has a (are) -> Adresa
// Student -> is a (este) -> StudentLicenta

class Adresa {
    char* locatie;
public:
    Adresa(const char* locatie = "Km 0 Universitate") {
        this->locatie = new char[strlen(locatie) + 1];
        strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
    }
    ~Adresa() {
        delete[] locatie;
    }
    friend ostream& operator<<(ostream& out, const Adresa& obj) {
        out << obj.locatie << endl;
        return out;
    }

};

class Student {
    // Compozitie (relatia "HAS A")
    // Studentul are o Adresa
protected:
    Adresa* adresa;
    char* nume;
public:
    Student(const char* nume = "Necunoscut", Adresa* adresa = new Adresa()) {
        
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);

        // copierea referinte (pointerului)
        this->adresa = adresa;
    }
    ~Student() {
        delete[] this->adresa;
        delete[] this->nume;
    }


    friend ostream& operator<<(ostream& out, const Student& obj) {
        out << obj.nume << " sta la adresa: " << *(obj.adresa) << endl;
        return out;
    }
};

// Mostenire (relatia "IS A")
// Student -> este clasa de baza (din care mostenesc)
// StudentLicenta -> este clasa derivata sau mostenita
class StudentLicenta : public Student {
    int anInmatriculare;
public:
    StudentLicenta(const char* nume = "Necunoscut", Adresa* adresa = new Adresa(), int an = 1) : Student(nume, adresa) {
        this->anInmatriculare = an;
    }

    friend ostream& operator<<(ostream& out, const StudentLicenta& obj) {

        out << "Studentul din anul:" << obj.anInmatriculare << obj.nume << " sta la adresa: " << *(obj.adresa) << endl;
        return out;
    }
};


// Creati o clasa StudentTaxa care sa mosteneasca din StudentLicenta si sa contina o taxa de platit


int main()
{
    Adresa address1;
    cout << address1;

    // address2 -> este pointer, adica obiectul este alocat dinamic
    Adresa* address2 = new Adresa("Dorobanti 5-7");
    cout << *address2;

    Student* student1 = new Student("John Doe");
    cout << *student1;

    Student* student2 = new Student("John Doe", address2);
    cout << *student2;

    Student* student3 = new Student("Mr President", new Adresa("Cotroceni Palace"));
    cout << *student3;

    StudentLicenta* student4 = new StudentLicenta( "Daria", new Adresa("Belvedere"));
    cout << *student4;

 

} 
