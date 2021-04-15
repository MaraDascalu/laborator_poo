//
//  Magazin_de_Cartier.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 14/04/2021.
//

#include <stdio.h>
#include "Magazin_de_Cartier.h"

Magazin_de_Cartier::Magazin_de_Cartier(std::string nume, std::vector<produs_cantitate> produse, int capacitate) : Magazin(nume, produse, capacitate) {}

int Magazin_de_Cartier::get_capacitate(){
    return Magazin::get_capacitate() - 5;
}
