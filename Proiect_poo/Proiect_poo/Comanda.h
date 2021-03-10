//
//  Comanda.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Comanda_h
#define Comanda_h

#include "Cumparator.h"

class Comanda{
    int nr_comanda;
    Cumparator c;
public:
    Comanda(int nr_comanda, Cumparator c);
    void pret_total();
    
};

#endif
