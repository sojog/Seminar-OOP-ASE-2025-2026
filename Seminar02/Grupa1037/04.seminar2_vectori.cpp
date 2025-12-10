// input + ouput + stream
#include <iostream>
using namespace std;


int main () {

    //     pozitii    0    1    2    3
    int vector[] = {101, 202, 303, 404};
    
    cout << "Valoarea de la prima pozitie este:" << vector[0] << endl;
    cout << "Adresa primului element" << vector << endl;

    int *ptr_vector = vector;
    cout << "Adresa primului element" << ptr_vector << endl;

    cout << "Valoarea de la prima pozitie este:" << *ptr_vector << endl << endl;

    cout << "Valoarea celui de-al doilea element" << vector[1] << endl;
    cout << "Valoarea celui de-al doilea element" << *(ptr_vector + 1) << endl;



    cout << "Valoarea celui de-al treilea element" << vector[2] << endl;
    cout << "Valoarea celui de-al treilea element" << *(ptr_vector + 2) << endl << endl;


    cout << "Adresa primului element" << vector << endl;
    cout << "Adresa primului element" << ptr_vector << endl;

    cout << "Adresa celui de-al doilea element" << vector + 1 << endl;
    cout << "Adresa celui de-al doilea element" << ptr_vector + 1 << endl;

    cout << "Adresa celui de-al treilea element" << vector + 2 << endl;
    cout << "Adresa celui de-al treilea element" << ptr_vector + 2 << endl << endl;

    cout << "Size of int " << sizeof(int) << endl;
    cout << "Size of float " << sizeof(float) << endl;
    cout << "Size of double " << sizeof(double) << endl;




    return 0;
}