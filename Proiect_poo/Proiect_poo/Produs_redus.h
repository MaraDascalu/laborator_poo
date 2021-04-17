//
//  Produs_redus.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 15/04/2021.
//

#ifndef Produs_redus_h
#define Produs_redus_h
#include "Furnizor_Magazin_Produs.h"

class Produs_redus : public Produs{
    int reducere;
public:
    Produs_redus(std::string nume, int pret);
    void set_reducere(int val);
    int get_pret();
};

#endif /* Produs_redus_h */
