
#include <iostream> // iostream = istream + ostream
#include <fstream> // fstream = ifstream + ofstream
using namespace std;


// 2. Pentru compounding_interval creați o enumerare cu valorile "zilnic", "lunar", "trimestrial" și "anual" ("daily", "monthly", "quarterly", "annually")
enum InvervalInvestitii {
    LUNAR,
    TRIMESTRIAL,
    SEMESTRIAL,
    ANUAL
};

// 1. Clasa are următorii parametri investitia_initiala (initial_investment), rată_dobânzii (interest_rate), interval_compus (compounding_interval), perioada (years), investitii (investments) (membru alocat dinamic)


// 14. Transformă clasa CalculatorInvestit (InvestmentCalculator) intr-o clasă template

template <int N>
class CalculatorInvestitiiTaxaAdministrare { 
protected:
    double taxa_administrare = N / 100.0; // taxa administrare in procente
};


class CalulatorInvestitiiFaraTaxa : public CalculatorInvestitiiTaxaAdministrare<0> { 

};

class CalulatorInvestitiiCuTaxa10Procente : public CalculatorInvestitiiTaxaAdministrare<10> { 
    
};



template<typename T>
class CalculatorInvestitii{
    // 

protected:
    double investitia_initiala;
    T rata_dobanzii;
    InvervalInvestitii interval_compus;
    int perioada;
    double* investitii;
    int numar_investitii;

    static double impozit_venit;

    // 12. Adăugați un membru implicit taxa_administrare și apoi moșteniti astfel încât să creați 2 clase cu valori diferite
    double taxa_administrare = 0.01; // 1% taxa administrare


public:

    CalculatorInvestitii(){
        investitia_initiala  = 0.0;
        rata_dobanzii = 0.0;
        interval_compus = ANUAL;
        perioada = 0;
        investitii = nullptr;
        numar_investitii = 0;
    }

    CalculatorInvestitii(double initial_investment, double interest_rate, InvervalInvestitii compounding_interval, int years) {
        investitia_initiala = initial_investment;
        rata_dobanzii = interest_rate;
        interval_compus = compounding_interval;
        perioada = years;
        investitii = nullptr;
        numar_investitii = 0;
    }

    // 3. Construiți constructor cu parametri, default, constructor de copiere, operatorul= și destructor

    // Class obiectNou = obiectExistent;
    CalculatorInvestitii (const CalculatorInvestitii &other) {

        this->investitia_initiala = other.investitia_initiala;
        this->rata_dobanzii = other.rata_dobanzii;
        this->interval_compus = other.interval_compus;
        this->perioada = other.perioada;
        this->numar_investitii = other.numar_investitii;

        if (other.investitii != nullptr) {
            investitii = new double[numar_investitii];
            for (int i = 0; i < numar_investitii; ++i) {
                investitii[i] = other.investitii[i];
            }
        } else {
            investitii = nullptr;
        }

    }


    // operatorul=
    // Obiect existent1;
    // Obiect existent2;
    // existent1 = existent2;

    CalculatorInvestitii& operator=(const CalculatorInvestitii &other) {
        if (this != &other) {
            delete[] investitii;
            investitia_initiala = other.investitia_initiala;
            rata_dobanzii = other.rata_dobanzii;
            interval_compus = other.interval_compus;
            perioada = other.perioada;
            numar_investitii = other.numar_investitii;

            if (other.investitii != nullptr) {
                investitii = new double[numar_investitii];
                for (int i = 0; i < numar_investitii; ++i) {
                    investitii[i] = other.investitii[i];
                }
            } else {
                investitii = nullptr;
            }
        }
        return *this;
    }
    
    // destructor
    ~CalculatorInvestitii() {
        delete[] investitii;
    }


    int getPerioada() {
        return perioada;
    }

    void setPerioada(int years) {
        if (years < 0)   return;
        perioada = years;
    }   


     // obiect.metoda(parametru);
     // obiect ***** parametru

     // cout << obiect << 32 << endl;

    friend ostream & operator<<  (ostream &consola, const CalculatorInvestitii &calc) {
        consola << "Investitia initiala: " << calc.investitia_initiala << endl;
        consola << "Rata dobanzii: " << calc.rata_dobanzii << endl;
        consola << "Perioada: " << calc.perioada << endl;
        return consola; 
    }


    //  7. Suprascrieți operatorul << pentru scriere in fisier text

    // ofstream este un tip de ostream ( mosteneste )
    friend ofstream & operator<<  (ofstream &fisiertxt, const CalculatorInvestitii &calc) {
        fisiertxt << calc.investitia_initiala << endl;
        fisiertxt << calc.rata_dobanzii << endl;
        fisiertxt << calc.perioada << endl;
        return fisiertxt; 
    }

    // 8. Suprascrieți operatorul >> pentru citire a unui obiect dintr-un fisier text
    // fisier >> obiect
    friend ifstream & operator>> (ifstream &fisier, CalculatorInvestitii &calc) {
        fisier >> calc.investitia_initiala;
        fisier >> calc.rata_dobanzii;
        fisier >> calc.perioada;
        return fisier;
    }

    double calculare_suma_totala() {
        
        // Formula pentru calcularea sumei totale cu dobanda compusa
        int n; // numarul de perioade de compunere pe an
        switch (interval_compus) {
            case LUNAR:
                n = 12;
                break;
            case TRIMESTRIAL:
                n = 4;
                break;
            case SEMESTRIAL:
                n = 2;
                break;
            case ANUAL:
                n = 1;
                break;
            default:
                n = 1;
        }

        double total = investitia_initiala * pow((1 + rata_dobanzii / n), n * perioada);
        return total;

    }


    // 9. Suprascrieți operatorii de comparație pentru a vedea suma totală dintre 2 conturi

    
    // calc1 > calc2
    
    // calc1.operator>(calc2)

    bool operator>( CalculatorInvestitii &other) {
        return this->calculare_suma_totala() > other.calculare_suma_totala();
    }

    // calc1 < calc2
    bool operator<( CalculatorInvestitii &other) {
        return this->calculare_suma_totala() < other.calculare_suma_totala();
    }
    // calc1 == calc2
    bool operator==(CalculatorInvestitii &other) {
        return this->calculare_suma_totala() == other.calculare_suma_totala();
    }


    // 10. Suprascrieți operatorul care face conversie la int de la obiect
    operator int() {
        return static_cast<int>(calculare_suma_totala());
    }

    operator double() {
        return calculare_suma_totala();
    }


    // 11. Suprascrieti operatorul [] care intoarce un anumit valoarea după anumită perioadă. Ex: [2] -> după 2 ani dacă 
    // Folosire obiect[2] -> returneaza valoarea dupa 2 ani


    double operator[](int an) { 

        if (an < 0 || an > perioada) {
            cout << "An invalid!" << endl;
            return -1;
        }

        int n; // numarul de perioade de compunere pe an
        switch (interval_compus) {
            case LUNAR:
                n = 12;
                break;
            case TRIMESTRIAL:
                n = 4;
                break;
            case SEMESTRIAL:
                n = 2;
                break;
            case ANUAL:
                n = 1;
                break;
            default:
                n = 1;
        }

        double valoare_dupa_an = investitia_initiala * pow((1 + rata_dobanzii / n), n * an);
        return valoare_dupa_an;

    }

};

//  12. Adăugați un membru implicit taxa_administrare și apoi moșteniti astfel încât să creați 2 clase cu valori diferite

// Relatie de mostenire. (is-a)
class CalculatorInvestitiiHighFee : public CalculatorInvestitii<double> { 

// taxa_administrare = 0.02 (2%)
public:
    CalculatorInvestitiiHighFee() : CalculatorInvestitii() {
        taxa_administrare = 0.02;
    }
    CalculatorInvestitiiHighFee(double initial_investment, double interest_rate, InvervalInvestitii compounding_interval, int years) : 
    
    CalculatorInvestitii(initial_investment, interest_rate, compounding_interval, years) {
        taxa_administrare = 0.02;
    }

};

// Relatie de mostenire. (is-a)
class CalculatorInvestitiiLowFee : public CalculatorInvestitii<double> { 

// taxa_administrare = 0.005 (0.5%)
public:
    CalculatorInvestitiiLowFee() : CalculatorInvestitii() {
        taxa_administrare = 0.005;
    }
    CalculatorInvestitiiLowFee(double initial_investment, double interest_rate, InvervalInvestitii compounding_interval, int years) : 
    
    CalculatorInvestitii(initial_investment, interest_rate, compounding_interval, years) {
        taxa_administrare = 0.005;
    }
};


// 13. Creați o clasă Portofolio care conține mai multe obiecte de tip CalculatorInvestit (InvestmentCalculator) și calculeaza totalul, minim, maxim, meadia. 

// Relatia este de tip has-a (compozitie)
class Portofolio { 
private:
    vector<CalculatorInvestitii<double>> investitii;
public:
    void adauga_investitie(const CalculatorInvestitii<double> &calc) {
        investitii.push_back(calc);
    }

    double calculare_total() {
        double suma = 0.0;
        for (auto &calc : investitii) {
            suma += calc.calculare_suma_totala();
        }
        return suma;
    }

    double calculare_minim() {
        if (investitii.empty()) {
             return 0.0;
        }
           
        double minim = investitii[0].calculare_suma_totala();
        for (auto &calc : investitii) {
            double suma = calc.calculare_suma_totala();
            if (suma < minim) {
                minim = suma;
            }
        }
        return minim;
    }

       double calculare_maxim() {
        if (investitii.empty()) {
             return 0.0;
        }

        double maxim = investitii[0].calculare_suma_totala();
        for (auto &calc : investitii) {
            double suma = calc.calculare_suma_totala();
            if (suma > maxim) {
                maxim = suma;
            }
        }
        return maxim;
    }
    double calculare_media() {
        if (investitii.empty()) {
             return 0.0;
        }

        double suma_totala = calculare_total();
        return suma_totala / investitii.size();
    }


};


// Initializare membru static
double CalculatorInvestitii<double>::impozit_venit = 0.16;


int main() {
    
    // constructor fara parametri
    CalculatorInvestitii<double> calc;

    // constructor cu parametri
    CalculatorInvestitii<double> calc2(1234, 0.09, LUNAR, 6);
    
    // constructor de copiere
    CalculatorInvestitii<double> calc3(calc2);

    // constructor de copiere
    CalculatorInvestitii<double> calc4 = calc2;
    // operatorul=
    CalculatorInvestitii<double> calc5;

    // calc5 este deja creat
    calc5 = calc2;

    cout << "Perioada obiectului 1 este:" << calc.getPerioada() << endl;


    cout << calc2 << endl;


    // Scriere in fisier text
    ofstream fisier_scris("calculator.txt");
    if (fisier_scris.is_open()) {
        fisier_scris << calc2;
        fisier_scris.close();
    } else {
        cout << "Eroare la deschiderea fisierului pentru scriere!" << endl;
    }


    // Citire din fisier text
    CalculatorInvestitii<double> calc6;

    ifstream fisier_citit("calculator.txt");
    if (fisier_citit.is_open()) {
        fisier_citit >> calc6;
        fisier_citit.close();
    } else {
        cout << "Eroare la deschiderea fisierului pentru citire!" << endl;
    }

    cout << "Obiectul citit din fisier este: " << endl;
    cout << calc6 << endl;



    cout << "Comparatie intre calc2 si calc3: " << endl;

    if (calc2 > calc3) {
    
        cout << "calc2 are suma totala mai mare decat calc3" << endl;
    } else if (calc2 < calc3) {
    
        cout << "calc2 are suma totala mai mica decat calc3" << endl;
    } else {
    
        cout << "calc2 are suma totala egala cu calc3" << endl;
    }
 


    // Conversie la double
    double suma_calculator2 = calc2;
    cout << "Suma totala a calc2 este (double): " << suma_calculator2 << endl;

    int suma_int_calculator2 = calc2;
    
    cout << "Suma totala a calc2 este (int): " << suma_int_calculator2 << endl;

    double valoarea_dupa_3_ani = calc2[3];

    cout << "Valoarea dupa 3 ani este: " << valoarea_dupa_3_ani << endl;
    

    Portofolio portofoliu;
    portofoliu.adauga_investitie(calc2);
    portofoliu.adauga_investitie(calc3);
    portofoliu.adauga_investitie(calc4);

    cout << "Suma total cal2 in portofoliu: " << calc2.calculare_suma_totala() << endl;
    cout << "Suma total cal3 in portofoliu: " << calc3.calculare_suma_totala() << endl;
    cout << "Suma total cal4 in portofoliu: " << calc4.calculare_suma_totala() << endl;

    cout << "Suma totala in portofoliu: " << portofoliu.calculare_total() << endl;


    return 0;
}

