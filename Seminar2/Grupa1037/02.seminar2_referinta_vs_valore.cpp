
// input + ouput + stream
#include <iostream>
using namespace std;


// void - nu intoarce nimic
// pasarea a valorii direct (fara referinta)
void incrementeaza_valoarea(int a){
    // a - este VARIABILA LOCALA
    cout << "Valoarea din functie inainte de incrementare este: " << a << endl; 
    a++;
    cout << "Valoarea din functie dupa incrementare este: " << a << endl; 
}

void incrementare_prin_referinta(int* ptr_a) {

    // ptr_a - este referinta (pointer) catre VARIABILA GLOBALA
    cout << "Valoarea pointerului catre a este:" << ptr_a << endl;
    cout << "Valoarea globala IN FUNCTIE a lui  a este:" << *ptr_a << endl;

    (*ptr_a)++;

    cout << "Valoarea globala IN FUNCTIE a lui  a este:" << *ptr_a << endl;

}


int main(){

     // a - este VARIABILA GLOBALA
    int a = 55;
    cout << "Numarul global:" << a << endl;

    incrementeaza_valoarea(a);
    cout << "Numarul global:" << a << endl;

    incrementare_prin_referinta(&a);

    cout << "Numarul global dupa schimbare prin referinta:"<< a << endl;

    return 0;

}