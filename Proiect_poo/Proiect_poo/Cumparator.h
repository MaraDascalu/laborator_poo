//
//  Header.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Header_h
#define Header_h
 
#include <string>
#include "Furnizor_Magazin_Produs.h"

class Cumparator{
    std::string nume;
    int telefon;
public:
    Cumparator(std::string nume, int telefon);
    void comanda(Produs &p, Magazin &m);
    void cumpara();
};

#endif /* Header_h */
