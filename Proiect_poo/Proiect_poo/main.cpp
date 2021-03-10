//
//  main.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#include <iostream>

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

class Cumparator{
    std::string nume;
    int telefon;
public:
    Cumparator(std::string nume, int telefon);
    void comanda(Produs &p, Magazin &m);
    void cumpara();
};

class Comanda{
    int nr_comanda;
    Cumparator c;
public:
    Comanda(int nr_comanda, Cumparator c);
    void pret_total();
    
};

int main(int argc, const char * argv[]) {
    Magazin m("nume", "adresa");
    Produs p("nume", 20);
    Furnizor f("nume");
    Cumparator c("nume", 752);
    Comanda (111, c);
}
