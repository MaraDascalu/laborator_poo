//
//  Cumparator_fidel.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 13/04/2021.
//

#ifndef Cumparator_fidel_h
#define Cumparator_fidel_h
#include "Cumparator.h"

class Cumparator_fidel : public Cumparator{
    int vechime;
    int discount = 0;
public:
    Cumparator_fidel(std::string nume, int telefon, int buget);
    void set_vechime(int val);
    int get_vechime();
    void set_discount();
    int get_discount();
};

#endif /* Cumparator_fidel_h */
