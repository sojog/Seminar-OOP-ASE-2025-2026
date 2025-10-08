
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std;
 


int main () {

    // Vector (array) - contine mai multe elemente
    // [] - operator de indexare
    // pozitii (indexi)      0,   1,   2,   3,   4  ( de la 0 .. lungimea-1 )
    int vector[]      =   {111, 222, 333, 444, 555}; 

    cout << "Adresa primului element:" << vector << endl;
    cout << "Valoarea primului element:" << vector[0] << endl;
    cout << "Valoarea ultimului element:" << vector[4] << endl;

    int *ptr_ind = vector;
    cout << "Pointer independent:" << ptr_ind << endl;
    cout << "Valoarea primului element:" << *ptr_ind << endl << endl;


    cout << "Lungimea (size) int-ului " << sizeof(int) << endl;
    cout << "Lungimea (size) float-ului " << sizeof(float) << endl;
    cout << "Lungimea (size) double-ului " << sizeof(double) << endl << endl;

    cout << "Valoare gasita la pozitia 0 prin pointer independent :" << *ptr_ind << endl;
    cout << "Valoare gasita la pozitia 1 prin pointer independent :" << *(ptr_ind + 1) << endl;
    cout << "Valoare gasita la pozitia 2 prin pointer independent :" << *(ptr_ind + 2) << endl;


}