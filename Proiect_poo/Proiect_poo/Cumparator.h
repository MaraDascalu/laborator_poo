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

class Cumparator{
    std::string nume;
    int telefon;
public:
    Cumparator(std::string nume, int telefon);
    Cumparator(const Cumparator &c);
    Cumparator &operator =(const Cumparator &cumparator);
    virtual ~Cumparator();
    void comanda(Produs &p, Magazin &m);
    void cumpara();
    friend std::ostream &operator<<(std::ostream &os,const Cumparator &cumparator);
};

#endif
