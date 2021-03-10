//
//  Header.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Header_h
#define Header_h

#include <string>

class Furnizor;

class Magazin{
    std::string nume;
    std::string adresa;
public:
    Magazin(std::string nume, std::string adresa);
    void primeste_marfa(Furnizor &f);
};

class Produs{
    std::string nume;
    int pret;
public:
    Produs(std::string nume, int pret);
    void se_gaseste_in(Magazin &m);
};

class Furnizor{
    std::string nume;
public:
    Furnizor(std::string nume);
    void livreaza(Produs &p, Magazin &m);
};
#endif /* Header_h */
