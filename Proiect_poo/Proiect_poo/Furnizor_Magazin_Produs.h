//
//  Header.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Furnizor_Magazin_Produs_h
#define Furnizor_Magazin_Produs_h

#include <string>

class Furnizor;

class Magazin{
    std::string nume;
    std::string adresa;
public:
    Magazin(std::string nume, std::string adresa);
    ~Magazin();
    void primeste_marfa(Furnizor &f);
};

class Produs{
    std::string nume;
    int pret;
public:
    Produs(std::string nume, int pret);
    ~Produs();
    void se_gaseste_in(Magazin &m);
};

class Furnizor{
    std::string nume;
public:
    Furnizor(std::string nume);
    ~Furnizor();
    void livreaza(Produs &p, Magazin &m);
};
#endif
