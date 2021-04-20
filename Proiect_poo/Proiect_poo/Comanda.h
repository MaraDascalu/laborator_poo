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
protected:
    int nr_comanda;
    int status;
    std::vector<produs_cantitate> lista_produse;
    std::unique_ptr<Cumparator> cumparator;

public:
    Comanda(int nr_comanda, int status, std::vector<produs_cantitate> lista_produse, std::unique_ptr<Cumparator> cumparator);
    ~Comanda();
    double pret_total();
    std::vector<produs_cantitate> &get_lista();
};

#endif
