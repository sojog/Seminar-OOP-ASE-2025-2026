#include <iostream>

using namespace std;

// clasa de baza
class Sportiv {
private: // accesibil din interiorul clasei
    string nume;
public:
    Sportiv(string nume):nume(nume){}
    friend ostream& operator<< (ostream& console, Sportiv& obj ){ 
        console << obj << endl;
        return console;
    }
};

int main(){

    // echivalent cu int *zile_dinamice;
    vector<int> zile = {101, 202, 303};
    
    for (int i : zile) {
        cout << "ziua: " << i << endl;
    }

    // string * culori;
    vector<string> culori = {"rosu", "albastru", "negru", "alb", "verde"};

     for (string i : culori) {
        cout << "culoarea: " << i << endl;
    }

    cout << endl << "Acesare un element din vector: " << zile[0] << endl ;
    cout << endl << "Acesare primul element din vector: " << zile.front() << endl ;

    cout << endl << "Acesare un element din vector: " << culori[3] << endl;
    cout << endl << "Acesare ultimul element din vector: " << culori.back() << endl ;



    Sportiv sp1("Mic"), sp2("Mediu"), sp3("Mare");
    vector<Sportiv> echipa = {sp1, sp2, sp3};

    for (Sportiv i : echipa) {
        cout << "Sportiv: " << i << endl;
    }
        
}