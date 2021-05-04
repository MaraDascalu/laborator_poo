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
protected:
    std::string nume;
    int telefon;
    int buget;
    
public:
    Cumparator(std::string nume, int telefon, int buget);
    Cumparator(const Cumparator &c);
    Cumparator &operator =(const Cumparator &cumparator);
    virtual ~Cumparator();  
    void adauga_produs(Comanda &comanda, produs_cantitate &p, Magazin &m);
    void elimina_produs(Comanda &comanda, produs_cantitate &p, Magazin &m);
    virtual int get_discount();
    friend std::ostream &operator<<(std::ostream &os,const Cumparator &cumparator);
};


#endif
