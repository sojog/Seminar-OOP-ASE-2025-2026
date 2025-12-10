
// input + ouput + stream
#include <iostream>
using namespace std;

int cel_mai_mare_numar (int x, int y) {
    // x, y - locale
    if(x > y){ 
        return x;
    }
    else{ 
        return y;
    }
}

// void - nu intoarce nimic
// pasarea a valorii direct (fara referinta)
void incrementeaza_valoarea(int a){
    cout << "Valoarea din functie inainte de incrementare este: " << a << endl; 
    a++;
    cout << "Valoarea din functie dupa incrementare este: " << a << endl; 
}



int main(){

    // << - operator de afisare
    cout << "Hello World!" << endl; // output to console
    cout << "Buna dimineata lumea" << "\n";
    cout << "Buna dimineata lumea" << "\n";

    // valoare - GLOBALA
    int x = 232;
    cout << "Valoarea lui x este: " << x << " care se afla la adresa:" << &x << endl;

    // pointer (adresa)
    int *pointer;
    // & - adresa 
    pointer = &x;

    int y = 100;
    cout << "Valoarea lui y este " << y << endl;

    int maxim =  cel_mai_mare_numar(x, y); // call function (argumente)
    cout << "Cel mai mare numar dintre x si y este: " << maxim << endl;


    incrementeaza_valoarea(y);
    cout << "Valoarea lui y dupa ce a fost apelata functia " << y << endl;



    return 0;
}