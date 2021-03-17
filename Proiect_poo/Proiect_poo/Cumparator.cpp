//
//  Cumparator.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include <iostream>
#include "Cumparator.h"

Cumparator::Cumparator(std:: string nume, int telefon) : nume(nume), telefon(telefon){}
Cumparator::Cumparator(const Cumparator &c){
    nume = c.nume;
    telefon = c.telefon;
}

Cumparator &Cumparator:: operator=(const Cumparator &cumparator){
    if (this != &cumparator)
    {
        nume = cumparator.nume;
        telefon = cumparator.telefon;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Cumparator &cumparator) {
    os << cumparator.nume <<"\n";
    return os;
}
void Cumparator::comanda(Produs &p, Magazin &m){ }
void Cumparator::cumpara(){ }
Cumparator::~Cumparator(){
    std::cout << "destructor cumparator";  } 



