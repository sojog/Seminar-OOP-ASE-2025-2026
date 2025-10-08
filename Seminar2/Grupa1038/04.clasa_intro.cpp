
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std; 

// CONVENTIE - numele clasei incepe cu LITERA MARE !!!
// CLASA este un sablon
class Masuratoare{ 
    
public:
    int temperatura = 20;
}; // se pune ";"  la finalul clasei


int main(){

    // VARIABILA GLOBALA
    int temperatura = 10;
    cout << "Temperatura globala: " << temperatura << endl;

    // CONVENTIE - numele obiectului cu litera MICA !!!
    Masuratoare obiect_masuratoare;
    cout << "Temperatura din obiect: " << obiect_masuratoare.temperatura  << endl;

    temperatura = 13;
    cout << "Noua temperatura globala: " << temperatura << endl;
    obiect_masuratoare.temperatura = 23;
    cout << "Noua temperatura din obiect: " << obiect_masuratoare.temperatura  << endl;


    return 0; 

}