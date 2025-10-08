
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std; 

// CONVENTIE - numele clasei incepe cu LITERA MARE !!!
// CLASA este un sablon
class Masuratoare{ 
private:
    int umiditatea = 40;
public:
    int temperatura = 20;

    // GET si SET
    int getUmiditate() {
        return umiditatea;
    }
    void setUmiditate(int newValue){
        umiditatea = newValue;
    }
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


    cout << "Umiditatea este:" << obiect_masuratoare.getUmiditate() << endl;
    obiect_masuratoare.setUmiditate(55);
    cout << "Umiditatea este:" << obiect_masuratoare.getUmiditate() << endl;

    return 0; 

}