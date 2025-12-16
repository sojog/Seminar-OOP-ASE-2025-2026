#include <iostream>

using namespace std;

// clasa de baza
class Sportiv {
private: // accesibil din interiorul clasei
    string nume;
    string prenume;
protected: // accesibil din clasa mostenita sau din interiorul clasei
    int an;
    int zi;
    int luna;
public: // accesibil din exterior, din clasa mostenita sau din interiorul clasei
    string echipament;
};
