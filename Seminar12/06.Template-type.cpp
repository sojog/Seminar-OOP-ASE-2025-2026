#include <iostream>

using namespace std;


template <typename T>
void printeazaVariabile( T variabila ){
    cout << "Variabila printata este: " << variabila << endl;
}

int main(){
    int a = 10;
    printeazaVariabile( a );

    float b = 10.312;
    printeazaVariabile( b );

    string c = "dasdashgdjhasg";
    printeazaVariabile( c );


    double d = 10.312;
    printeazaVariabile<int>( d );


}