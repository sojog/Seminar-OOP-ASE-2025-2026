/*
Creați o clasă SalaDeCinema care să contorizeze spectatorii prezenți la un film și
					durata de vizionare rămasă pentru fiecare.
Sala are un preț fix al biletului și un număr maxim de locuri disponibile.

1. Implementați clasa cu 1 membru alocat dinamic (de exemplu, numele sălii), unul constant (prețul biletului)
și unul static (numărul total de spectatori care au intrat vreodată în toate sălile de acest tip).

2. Creați constructori și destructor (cu eliberare corectă a memoriei).

3. Supraincărcați operatorii << (afișează starea sălii: locuri ocupate, încasări, etc.) 
și ++ (adaugă un spectator nou în sală – dacă mai sunt locuri libere).
*/

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class SalaDeCinema {

private:
	int pretBilet;
	int capacitate;
	char* denumire;
	static int totalSpectatoriInToateSalile;
	int totalSpectatoriSalaCurenta;
	const int nrSala;
	static int contor;


public:

	// constructor implicit

	SalaDeCinema():nrSala(++contor)
	{
		this->capacitate = 100;
		this->pretBilet = 10;
		this->denumire = new char[strlen("Denumire") + 1];
		//strcpy(this->denumire, "Denumire");.
		strcpy_s(this->denumire, strlen("Denumire") + 1, "Denumire");
		
	}

	SalaDeCinema(int capacitate, int pretBilet, const char* denumire) :nrSala(++contor)
	{	
		this->pretBilet = pretBilet;
		this->capacitate = capacitate;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

	}

	~SalaDeCinema() {
		delete[] denumire;
	}

	friend ostream& operator<<(ostream& consola, const SalaDeCinema& sala)
	{
		consola << "pretul unui bilet " << sala.pretBilet << "capacitatea " << sala.capacitate << endl;
		return consola;

	}
	

	operator int() {
		return this->nrSala;
	}

	SalaDeCinema& operator++() {

		if (this->capacitate - this->totalSpectatoriSalaCurenta != 0)
		{
			this->totalSpectatoriInToateSalile += 1;
			this->totalSpectatoriSalaCurenta += 1;
		}
		return*this;
	}


};

int SalaDeCinema::contor = 0;

int SalaDeCinema::totalSpectatoriInToateSalile = 0;

int main() {
	SalaDeCinema s1; 
	cout << s1;

	SalaDeCinema s2(100, 20, "Luceafar");

	int nr_sala_2 = s2;
	cout << nr_sala_2 << endl;
}