
#include <iostream> // input + output
using namespace std;

// conventie numele clasei cu litera mare + camelCase
class ContBancar { 

private: // este vizibil doar in interiorul clasei
    
    int balanta; // automat in private
    const int idCont; // constant
    static int counter; // apartine la nivel de clasa 

    //     [  _, _, _, ]
    int nr_tranzactii;
    int* listaTranzactii; // este un membru alocat dinamic

     void adaugaTranzactia(int valoare){
        // PRINCIPIUL DRY -> DON'T REPEATE YOURSELF
        this->balanta += valoare;

        if (nr_tranzactii == 0) {
            this->listaTranzactii = new int[1];
            this->listaTranzactii[0] = valoare;
        } else {
            // alocare a unui vector cu o suprafata mai mare -> [ _, _ ]
            int *temp = new int[nr_tranzactii + 1];

            // copiere din vectorul deja existent  -> [ 32, _ ]
            for(int i=0; i < nr_tranzactii ; i++ ){
                temp[i] = listaTranzactii[i];
            }

            // pe ultima pozitie adaug noua valoare
            temp[nr_tranzactii]  = valoare;
            

            // sterg primul vector cu tranzactii
            delete[] listaTranzactii;
            listaTranzactii = temp;
        }
        nr_tranzactii++;
    }

public: // este vizibil in afara clasei
    static int taxaAnuala;
    // constructor este o metoda speciala care are rol de intializare a atributelor (variabilele clasei)
    // ContBancar() {
    //     this->balanta = 0;
    // }

    // semnatura functie. = numele functiei + parametri(tipul lor)
    // CONSTRUCTOR DEFAULT + CONSTRUCTOR CU 1 parametru
    ContBancar(int balanta = 0) : idCont(++counter){  // constructor cu 1 parametru
        this->balanta = balanta;
        this->listaTranzactii = nullptr;
         int nr_tranzactii = 0;
    }

    //      [ OBIECT1
    //          [_, _, _, _]
    //      ]

    //      [ OBIECT1
    //          [_, _, _, _]
    //      ]

    ContBancar(const ContBancar& obiect) : idCont(++counter) {
        this->balanta = obiect.balanta;
        this->nr_tranzactii = obiect.nr_tranzactii;

        this->listaTranzactii = new int[nr_tranzactii];
        // [3, 4, 2, 41]
        // [_, _, _, _]

         for(int i=0; i < nr_tranzactii ; i++ ){
                this->listaTranzactii[i] = obiect.listaTranzactii[i];
            }

    }

    // aici contul deja exista
    ContBancar& operator=(const ContBancar& obiect){

        if (this == &obiect) {
            return *this;
        }

        // stergem lista de tranzactii initiala
        delete[] listaTranzactii;
        this->nr_tranzactii = obiect.nr_tranzactii;

        this->listaTranzactii = new int[nr_tranzactii];
        // [3, 4, 2, 41]
        // [_, _, _, _]

        for(int i=0; i < nr_tranzactii ; i++ ){
            this->listaTranzactii[i] = obiect.listaTranzactii[i];
        }
        return *this;


    }


    // DESTRUCTOR -> 1 singur
    ~ContBancar (){
        cout << "Destructorul clasei ContBancar este apelat " << endl;
        // aici se sterg elementele alocate dinamic 
        delete[] listaTranzactii;
    }



    // metoda - este o functie a clasei
    int getBalanta (){
        return this->balanta;
    }
    // obiect += 10
    // obiect.operator+= (10)
    ContBancar& operator+=(int valoare) {
        adaugaTranzactia(valoare);
         return *this;
    }
    ContBancar& operator-=(int valoare) {
        adaugaTranzactia(-valoare);
         return *this;
    }
 
    // ++obiect 
    ContBancar& operator++(){
        adaugaTranzactia(1);
        return *this;
    }

       // --obiect 
    ContBancar& operator--(){
        adaugaTranzactia(-1);
        return *this;
    }


    // obiect ++  
    ContBancar& operator++(int){ 
        adaugaTranzactia(1);
        return *this;  // returneaza starea
    }

      // obiect -- 
    ContBancar& operator--(int){ 
        adaugaTranzactia(-1);
        return *this;  // returneaza starea
    }

    int getTranzactiaCuNumarul(int index) {
        if ((index < 0) || (index > nr_tranzactii)){
            cout << "Index gresit" << endl;
        }
        return listaTranzactii[index];
    }

    // obiect[3] -> int
    int operator[] (int index) {
        if ((index < 0) || (index > nr_tranzactii)){
            cout << "Index gresit" << endl;
        }
        return listaTranzactii[index];
    }

    operator int(){
        return this->balanta;
    }

    // orice operator este o functie/metoda
    // cout.operator<<(obiect)

    // cout << obiect

    friend ostream& operator<<(ostream& out, ContBancar& obiect); 

    // [32] -> [32, 55]
    // [ _, _ ] -> [ 32 ,  55]

   

}; // terminate in ;

int ContBancar::taxaAnuala = 10;
int ContBancar::counter = 0;

// cout << obiect1 << obiect2 << obiect3
// cout << obiect2 << obiect3
// cout << obiect3
// cout

ostream& operator<<(ostream& out, ContBancar& obiect) { 
     out << "Contul cu numarul " <<  obiect.idCont << " are balanta: " << obiect.balanta << endl;

     for (int i=0; i< obiect.nr_tranzactii; i++){
        cout << " Tranzactia nr " << (i + 1) << " in valoare de " << obiect.listaTranzactii[i] << endl;
     }

     return out;
}

// scopul functiei main este de a incepe programul
int main(){


    cout << "Taxa de administrare a contului este: " << ContBancar::taxaAnuala << endl;


    ContBancar cont1; // cream un obiect de tipul -> foloseste constructorul default (fara parametri)
    cout << "Balanta de la contul 1 este: " << cont1.getBalanta() << endl;


    ContBancar cont2(200);
    cout << "Balanta de la contul 2 este: " << cont2.getBalanta() << endl;

    cont2 += 40;

    cont2 -= 11;

    cout << cont2;

    ++cont2;
    cout << cont2;

    --cont2;
    cout << cont2;

    cont2--;

    int balantaTransformata = cont2;
    cout << "valoare transformata in int este: " << balantaTransformata << endl;

    cout << cont2 << endl;


    cout << "Prima tranzactie " << cont2.getTranzactiaCuNumarul(0) << endl;
    cout << "Prima tranzactie " << cont2[0] << endl;


    // 
    // cout << "Ultima tranzactie " << cont2[4]<< endl;
    // cout << "Ultima tranzactie " << cont2.getTranzactiaCuNumarul(3) << endl;



    // Constructor de copiere
    ContBancar cont3 = cont2;

    cout << "Vom printa obiectul cont3" << endl;
    cout << cont3;


}