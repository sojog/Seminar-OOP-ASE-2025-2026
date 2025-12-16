// Seminar11-1038.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

/* Clasa RECTANGLE deţine următoarele caracteristici:
 - Lungimea și lățimea dreptunghiului.

Clasa deţine următoarele implementări:
 - operatorul de afisare - se printează dimensiunile dreptunghiului;
 - area - calculează aria dreptunghiului.
 - isSquare - spune dacă un dreptunghi este pătrat
*/

class Rectangle {
protected:
    int lungime;
    int latime;
public:
    Rectangle(int lungime = 0, int latime = 0) {
        cout << "Constructorul din RECTANGLE este apelat" << endl;
        this->lungime = lungime;
        this->latime = latime;
    }

    friend ostream& operator<< (ostream& output, const Rectangle& obj) {
        output << obj.lungime << endl << obj.latime << endl;
        return output;
    }
    // Rectangle se schimba -> nu mai poate fi const
    friend istream& operator>> (istream& input, Rectangle& obj) {
       
        cout << "Introduceti noua lungime " << endl;
        
        input >> obj.lungime;

        cout << "Introduceti noua latime " << endl;

        input >> obj.latime;

        return input;
    }
    int area() {
        return this->latime * this->lungime;
    }
    
    bool isSquare() {
        return this->latime == this->lungime;
    }
};

class Square : public Rectangle {


public:
    Square(int latura):Rectangle(latura, latura){
        cout << "Constructorul din SQUARE este apelat" << endl;
    }

    friend istream& operator>> (istream& input, Square& obj) {

        cout << "Introduceti noua latura " << endl;

        input >> obj.lungime;
        obj.latime = obj.lungime;

        return input;
    }
};

int main()
{
    //Rectangle masa;
    //cout << masa;


    //cin >> masa;
    //cout << masa;

    //cout << masa.area() << endl;

    Square cap(20);
    cout << cap.area() << endl;
    cout << "Is Square : " << cap.isSquare() << endl;

    cin >> cap;
    cout << cap;
    cout << cap.area() << endl;

    ofstream file_output("numere.txt");
    if (file_output.is_open()) {
        file_output << cap << endl;
        file_output.close();
    }

    Square fereastra(30);

    ifstream file_input("numere.txt");
    if (file_input.is_open()) {
        file_input >> fereastra;

    }

    cout << "Dupa citire din fisier: " << fereastra << endl;
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
