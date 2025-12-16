// Creați clasa Sportiv care conține un nume, prenume și data nasterii.
#include <iostream>
#include <fstream>   // fstream este mostenit din ostream
// fstream = ofstream + ifstream
using namespace std;

class Sportiv {
    string nume;
    string prenume;
    int an;
    int zi;
    int luna;

public:
    // Constructor poate fi doar 1
    Sportiv(string nume, string prenume, int an, int zi, int luna): nume(nume), prenume(prenume), an(an), zi(zi), luna(luna){     
    }
    // cout << obj
    friend ostream& operator<< (ostream& console, Sportiv& obj ){
        console << obj.nume << " " << obj.prenume << " nascut pe " << obj.zi << "-" << obj.luna << "-" << obj.an << endl;
        return console;
    }


    friend ofstream& operator<< (ofstream& console, Sportiv& obj ){
        console << obj.nume <<  endl << obj.prenume << endl << obj.zi << endl << obj.luna << endl << obj.an << endl;
        return console;
    }

    // file_reader >> obj
    friend ifstream& operator>> (ifstream& file, Sportiv& obj ) {
        file >> obj.nume;
        file >> obj.prenume;
        file >> obj.zi;
        file >> obj.luna;
        file >> obj.an;

        return file;
    }

};

int main (){
    Sportiv sp1("Ionescu", "Ion", 2000, 5, 12);
    // cout este de tip ostream
    cout << sp1;

    // output stream -> flux de scriere
    ofstream file_writer("datele_unui_sportiv_v2.txt");
    if (file_writer.is_open()){
        file_writer << sp1;
    }

    // input stream -> flux de citire
    ifstream file_reader("sportiv.txt");

    Sportiv sp2 = sp1;

    if (file_reader.is_open()){ 
        file_reader >> sp2;
        cout << "Obiectul citit este: " << sp2;
    }








}
