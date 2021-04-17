//
//  Furnizor_Magazin_produs.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include "Furnizor_Magazin_Produs.h"
#include <algorithm>

Magazin::Magazin(std::string nume,std::vector<produs_cantitate> produse, int  capacitate) : nume(nume), produse(produse), capacitate_maxima(capacitate){}
void Magazin::primeste_marfa(Furnizor &furnizor){furnizor.livreaza(*this);}
//void Magazin::set_capacitate(int val){
//    capacitate_maxima = val;
//}
int Magazin::get_capacitate(){
    return this->capacitate_maxima;
}
std::vector<std::tuple<Produs, int>>& Magazin::get_produse(){
    return produse;
}
bool Magazin::exista(Produs &p){
    auto var = std::find_if(produse.begin(), produse.end(), [&p](auto &pr){
        return std::get<0>(pr).get_nume() == p.get_nume();
    });
    return var != produse.end();
}
bool Magazin::e_disponibil(Produs &p){
    auto var = std::find_if(produse.begin(), produse.end(), [&p](auto &pr){
        return (std::get<0>(pr).get_nume() == p.get_nume() && std::get<1>(pr) != 0);
    });
    return var != produse.end();
}
Magazin::~Magazin(){}

Produs::Produs(std::string nume, int pret) : nume(nume), pret(pret){}
void Produs::se_gaseste_in(Magazin &magazin){}
int Produs::get_pret(){
    return pret;
}
std::string Produs::get_nume(){
    return nume;
}
std::ostream &operator<<(std::ostream &os, const Produs &produs){
    os<< produs.nume;
    return os;
}
Produs::~Produs(){}

Furnizor::Furnizor(std::string nume) : nume(nume){}
void Furnizor::livreaza(Magazin &magazin){
    auto& produse = magazin.get_produse();
    for (auto& produs : produse)
        std::get<1>(produs) = magazin.get_capacitate();
}
Furnizor::~Furnizor(){} 




