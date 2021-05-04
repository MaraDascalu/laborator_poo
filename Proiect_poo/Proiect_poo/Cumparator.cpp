//
//  Cumparator.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include <iostream>
#include <cstdlib>
#include "Cumparator.h"
#include "Comanda.h"

Cumparator::Cumparator(std:: string nume, int telefon, int buget) : nume(nume), telefon(telefon), buget(buget){} 
Cumparator::Cumparator(const Cumparator &c){
    nume = c.nume;
    telefon = c.telefon;
    buget = c.buget;
}

Cumparator &Cumparator:: operator=(const Cumparator &cumparator){
    if (this != &cumparator)
    {
        nume = cumparator.nume;
        telefon = cumparator.telefon;
        buget = cumparator.buget;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Cumparator &cumparator) {
    os << cumparator.nume <<" "<< cumparator.telefon<<" "<< cumparator.buget<<"\n";
    return os;
}
void Cumparator::adauga_produs(Comanda &comanda, produs_cantitate &p, Magazin &m){
    std::vector<produs_cantitate> &lista = comanda.get_lista();
    auto &stoc = m.get_produse();
    bool ok = 0;
    for (int i = 0; i< lista.size(); i++)
        if (std::get<0>(lista[i]).get_nume() == std::get<0>(p).get_nume())
        {
            if (m.e_disponibil(std::get<0>(p)) == 0)
            {
                ok = 1;
                throw std::invalid_argument("Produsul "+ std::get<0>(p).get_nume()+  " nu este disponibil pe stoc!\n");
            }
            
            std::get<1>(lista[i]) += std::get<1>(p);
            ok = 1;
            break;
        }
    if (!ok) lista.push_back(p);
    for (int i = 0 ; i < stoc.size(); i++)
    {
        if (std::get<0>(*stoc[i]).get_nume() == std::get<0>(p).get_nume())
        {
            std::get<1>(*stoc[i]) -= std::get<1>(p);
        }
    }
};
void Cumparator::elimina_produs(Comanda &comanda, produs_cantitate &p, Magazin &m){
    std::vector<produs_cantitate> &lista = comanda.get_lista();
    auto &stoc = m.get_produse();
    bool ok = 0;
    for (int i = 0; i < lista.size(); i++)
        if(std::get<0>(lista[i]).get_nume() == std::get<0>(p).get_nume())
        {
            ok = 1;
            lista.erase(lista.begin() + i);
        }
    if (ok)
    for (int i = 0 ; i < stoc.size(); i++)
    {
        if (std::get<0>(*stoc[i]).get_nume() == std::get<0>(p).get_nume())
        {
            std::get<1>(*stoc[i]) += std::get<1>(p);
        }
    }
};

int Cumparator::get_discount(){
    return 0;
}
Cumparator::~Cumparator(){
//    std::cout << "destructor cumparator";
    
}


