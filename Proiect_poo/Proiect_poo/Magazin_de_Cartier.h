//
//  Magazin_de_Cartier.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 14/04/2021.
//

#ifndef Magazin_de_Cartier_h
#define Magazin_de_Cartier_h
#include "Furnizor_Magazin_Produs.h"

class Magazin_de_Cartier : public Magazin{
public:
    Magazin_de_Cartier( std::string nume, std::vector<produs_cantitate> produse, int capacitate);
    int get_capacitate();
};
#endif /* Magazin_de_Cartier_h */
