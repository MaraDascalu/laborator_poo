//
//  Produs_redus.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 15/04/2021.
//

#include <stdio.h>
#include "Produs_redus.h"

Produs_redus:: Produs_redus(std::string nume, int pret) : Produs(nume, pret){}

void Produs_redus::set_reducere(int val){
    reducere = val;
}
int Produs_redus::get_pret(){
    return Produs::get_pret() - Produs::get_pret() * reducere / 100;
}
