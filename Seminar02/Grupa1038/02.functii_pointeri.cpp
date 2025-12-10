
// input + output ( CONTINE cout, cin )
#include <iostream>
// std::cout
using namespace std;

// PASAREA unei variabile prin valoare (SE CREAZA O COPIE)
void incrementeaza_prin_valoare(int x){
    // x - este copiat
    x++;
    cout << "(FUNCTIE - local) x = " << x << endl;
}

// PASAREA UNEI variabile prin referinta (SE MODIFICA)
void incrementeaza_prin_referinta(int* x){
    // x este cel primit prin referinta
    (*x)++;
    cout << "(FUNCTIE cu referinta - local) x = " << *x << endl;
}

void incrementeaza_prin_adresa(int &x){ 
    x++;
    cout << "(FUNCTIE - local) x = " << x << endl;
}
    


int main() {
    int x = 10;

    incrementeaza_prin_valoare(x);
    cout << "(MAIN - global). x = " << x << endl;

    incrementeaza_prin_referinta(&x);
    cout << "(MAIN - global). x = " << x << endl;

    incrementeaza_prin_adresa(x);
    cout << "(MAIN - global). x = " << x << endl;


    return 0;
}