
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std;

int main() {

    cout << "Hello World!" << endl; // endl = newline
    // \n este echivalent cu endl
    cout << "Hello World!" << endl << "Buna dimineata" << "\n"; // endl = newline


    // VARIABILA - int, float, double, char, bool
    int a;
    cout << "Valoarea lui a este:" << a << endl;
    cout << "Adresa lui a este: " << &a << endl;

    a = 200;
    cout << "Valoarea lui a este:" << a << endl;
    cout << "Adresa lui a este: " << &a << endl; 

    // POINTER -> * in fata la declarare
    int* ptr_a;
    ptr_a = &a;
    cout << "Valoarea pointerului" << ptr_a << endl;
    cout << "Valoarea de la point" << *ptr_a << endl;


    return 0;

}
