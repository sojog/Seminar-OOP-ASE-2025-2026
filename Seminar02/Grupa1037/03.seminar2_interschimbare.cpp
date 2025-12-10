// input + ouput + stream
#include <iostream>

// [20]
// [30]
// aux [20]


void interschimbare(int* x, int* y) {
    int aux;
    aux = *y;
    *y = *x;
    *x = *y;
}


int main() {
    std::cout << "Interschimbarea a doua valori prin referinta" << std::endl;
    
    int primul = 30;
    int ultimul = 400;

    std::cout << "Valoarea primului initial este:" << primul << std::endl;
    std::cout << "Valoarea ultimului initial este:" << ultimul << std::endl;

    interschimbare(&primul, &ultimul);
    std::cout << "Valoarea primului dupa interschimbare este:" << primul << std::endl;
    std::cout << "Valoarea ultimului dupa interschimbare este:" << ultimul << std::endl;



    int *ptr_prim, *ptr_ultim;
    *ptr_prim = 55;
    *ptr_ultim = 99;
    interschimbare(ptr_prim, ptr_ultim);
    std::cout << "Valoarea de la primul POINTER dupa interschimbare este:" << *ptr_prim << std::endl;
    std::cout << "Valoarea de la ultimul POINTER dupa interschimbare este:" << *ptr_ultim << std::endl;



    return 0;

}