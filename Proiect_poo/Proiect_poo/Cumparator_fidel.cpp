//
//  Cumparator_fidel.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 13/04/2021.
//

#include <stdio.h>
#include "Cumparator_fidel.h"


Cumparator_fidel::Cumparator_fidel(std::string nume, int telefon, int buget): Cumparator(nume, telefon, buget){};
Cumparator_fidel::Cumparator_fidel(std::string nume, int telefon, int buget, int vechime) : Cumparator(nume, telefon, buget), vechime(vechime)
{
    if (vechime >= 2)
        discount = 15;
    else if (vechime >= 1)
            discount = 10;
}

void Cumparator_fidel::set_vechime(int val){
    vechime = val;
}
int Cumparator_fidel::get_vechime(){
    return vechime;
}

void Cumparator_fidel::set_discount(){
    if (vechime >= 2)
        discount = 15;
    else if (vechime >= 1)
            discount = 10;
}

int Cumparator_fidel::get_discount(){
    return discount;
}
