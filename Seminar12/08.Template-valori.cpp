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

template <int NR_MEMBRI>
class Echipa {

    Sportiv* membri;
public:
    Echipa(){
        this->membri = nullptr;
    }
    Echipa(Sportiv * membri){
        this->membri = new Sportiv[NR_MEMBRI];
        for (int i=0; i< NR_MEMBRI; i++) {
            this->membri[i] = membri[i];
        }
    }

};

class EchipaFotbal:Echipa<11> {

};

class EchipaHandbal:Echipa<5> {

};

int main(){ 
    Echipa<11> echipa1;
    EchipaFotbal echipa2;

}