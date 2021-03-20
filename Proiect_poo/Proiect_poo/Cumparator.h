//
//  Header.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Cumparator_h
#define Cumparator_h
 
#include <string>
#include "Furnizor_Magazin_Produs.h"

class Comanda;

class Cumparator{
    std::string nume;
    int telefon;
    int buget;
    
public:
    Cumparator(std::string nume, int telefon, int buget);
    Cumparator(const Cumparator &c);
    Cumparator &operator =(const Cumparator &cumparator);
    virtual ~Cumparator();  
    void comanda(Comanda &c, Magazin &m);
    void adauga_produs(Comanda &comanda, produs_cantitate &p);
    void elimina_produs(Comanda &comanda, produs_cantitate &p);
    friend std::ostream &operator<<(std::ostream &os,const Cumparator &cumparator);
};

#endif
