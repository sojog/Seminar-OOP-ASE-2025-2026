


// Seminar11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // ostream + istream
#include <fstream> 
using namespace std;
/*

1. Trebuie creată clasa Rectangle care să abstractizeze un dreptunghi dintr-un plan (lungime și lățime).

Clasa deţine următoarele caracteristici:
 - Lungimea și lățimea dreptunghiului.

Clasa deţine următoarele implementări:

 - operatorul de afisare - se printează dimensiunile dreptunghiului;
 - area - calculează aria dreptunghiului.
 - isSquare - spune dacă un dreptunghi este pătrat


2. Creați clasa Square care să moștenească din Rectangle (lățimea și lungimea sunt egale)
*/


class Rectangle {
    int lungime;
    int latime;
public:

    Rectangle(int lung = 0 , int lat = 0) {
        lungime = lung;
        latime = lat;
    }

    friend ostream& operator<< (ostream& out, Rectangle& obj) {
        out << obj.lungime << " x " << obj.latime << endl;
        return out;
    }

    friend ofstream& operator<< (ofstream& out, Rectangle& obj) {
        out << obj.lungime << endl;
        out << obj.latime << endl;
        return out;
    }

    friend istream& operator>> (istream& input, Rectangle& obj) {
        cout << "Introdu o noua lungime " << endl;
        input >> obj.lungime;
        cout << "Introdu o noua latime" << endl;
        input >> obj.latime;

        return input;
    }

    friend ifstream& operator>> (ifstream& input, Rectangle& obj) {
        input >> obj.lungime;
        input >> obj.latime;

        return input;
    }

    int aria() {
        return this->lungime * this->latime;
    }
    bool isSquare() {
        return this->lungime == this->latime;
    }
};

class Square : public Rectangle {
public:
    Square(int latura = 0):Rectangle(latura, latura){}
};


void afiseaza_aria_unei_forme(Rectangle obiect) {
    cout << obiect.aria() << endl;
}

int main()
{
    Rectangle dreptunghi1(5, 3);
    cout << dreptunghi1;
    cout << dreptunghi1.aria() << endl;
    cout << "Is square: " << dreptunghi1.isSquare() << endl;

    //cin >> dreptunghi1;
    cout << dreptunghi1;

    Square patratel(5);
    cout << patratel;
    cout << patratel.isSquare() << endl;

    afiseaza_aria_unei_forme(patratel);


    // output file stream
    // SUS trebuie inclus fstream -> #include <fstream>
    ofstream file("ouput.txt");
    if (file.is_open()) {
        cout << "Am deschis fisierul" << endl;
        file << patratel;

        file.close();
        cout << "Am terminat de scris in fisier" << endl;
    }


    Rectangle dreptunghi2(11, 12);
    cout << dreptunghi2;

    ifstream input_file("input.txt");
    int valoare_citita;
    if (input_file.is_open()) {
        input_file >> valoare_citita;
        cout << "valoarea_citita este:" << valoare_citita << endl;
    }


    ifstream input("output.txt");
    if (input.is_open()) {
        input >> dreptunghi2;
    }
    cout << dreptunghi2;
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
