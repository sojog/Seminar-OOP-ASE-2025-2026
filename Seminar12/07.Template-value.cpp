#include <iostream>

using namespace std;


template <int N>
class Cufar{
    int valori[N];
public:
    int nrValori() {
        return N;
    }
};

int main(){
    Cufar<5> depozit;
    cout << depozit.nrValori() << endl;


    Cufar<23> depozit2;
    cout << depozit2.nrValori() << endl;

}