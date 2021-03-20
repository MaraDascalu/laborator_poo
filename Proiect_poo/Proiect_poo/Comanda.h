//
//  Comanda.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Comanda_h
#define Comanda_h

#include "Cumparator.h"
#include <vector>

class Comanda{
    int nr_comanda;
    int status;
    std::vector<produs_cantitate> lista_produse;
    Cumparator c;

public:
    Comanda(int nr_comanda, int status, Cumparator c);
    ~Comanda();
    double pret_total();
    
};

#endif
