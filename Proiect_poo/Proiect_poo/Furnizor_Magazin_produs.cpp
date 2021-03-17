//
//  Furnizor_Magazin_produs.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 17/03/2021.
//

#include "Furnizor_Magazin_produs.h"

Magazin::Magazin(std::string nume, std::string adresa) : nume(nume), adresa(adresa) {}
void Magazin::primeste_marfa(Furnizor &furnizor){}
Magazin::~Magazin(){}

Produs::Produs(std::string nume, int pret) : nume(nume), pret(pret){}
void Produs::se_gaseste_in(Magazin &magazin){}
Produs::~Produs(){}

Furnizor::Furnizor(std::string nume) : nume(nume){}
void Furnizor::livreaza(Produs &produs, Magazin &magazin){}
Furnizor::~Furnizor(){} 




