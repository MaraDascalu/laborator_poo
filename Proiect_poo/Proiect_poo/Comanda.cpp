//
//  Comanda.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include "Comanda.h"
#include "Cumparator.h"

Comanda::Comanda(int nr_comanda, int status,std::vector<produs_cantitate> lista_produse ,Cumparator c) : nr_comanda(nr_comanda), status(status),lista_produse(lista_produse) ,c(c){} 
double Comanda::pret_total(){
    double pret = 0;
    for (auto &produs: lista_produse)
        pret += std::get<0>(produs).get_pret() * std::get<1>(produs);
    return pret;
}
Comanda::~Comanda(){ }
std::vector<produs_cantitate>& Comanda::get_lista(){
    return lista_produse;
}
