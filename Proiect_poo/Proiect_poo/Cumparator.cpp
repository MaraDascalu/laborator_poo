//
//  Cumparator.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include <iostream>
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
void Cumparator::adauga_produs(Comanda &comanda, produs_cantitate &p){
    std::vector<produs_cantitate> lista = comanda.get_lista();
    bool ok = 0;
    for (int i = 0; i< lista.size(); i++)
        if (std::get<0>(lista[i]).get_nume() == std::get<0>(p).get_nume()){
            std::get<1>(lista[i]) += std::get<1>(p);
            ok = 1;
            break;
        }
    if (!ok) lista.push_back(p);
};
void Cumparator::elimina_produs(Comanda &comanda, produs_cantitate &p){
    std::vector<produs_cantitate> lista = comanda.get_lista();
    for (int i = 0; i < lista.size(); i++)
        if(std::get<0>(lista[i]).get_nume() == std::get<0>(p).get_nume())
            lista.erase(lista.begin() + i);
};
//void Cumparator::comanda(Comanda &c, Magazin &m){ }
Cumparator::~Cumparator(){
//    std::cout << "destructor cumparator";
    
}

void Cumparator_fidel::set_vechime(int val){
    vechime = val;
}
int Cumparator_fidel::get_vechime(){
    return vechime;
}

void Cumparator_fidel::set_discount(const Cumparator_fidel &cumparator_fidel){
    if (vechime >= 2)
        discount = 15;
    else if (vechime >= 1)
            discount = 10;
}


