//
//  main.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#include <iostream>
#include "Furnizor_Magazin_Produs.h"
#include "Cumparator.h"
#include "Comanda.h"


int main(int argc, const char * argv[]) {
    Magazin m("nume", "adresa");
    Produs p("nume", 20);
    Furnizor f("nume");
    Cumparator c("nume", 752);
    Comanda (111, c);
}
