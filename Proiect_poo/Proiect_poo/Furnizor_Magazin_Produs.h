//
//  Header.h
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#ifndef Furnizor_Magazin_Produs_h
#define Furnizor_Magazin_Produs_h

#include <string>
#include <vector>
#include <tuple>

class Furnizor;
class Magazin;

class Produs{
protected:
    std::string nume;
    int pret;
public:
    Produs(std::string nume, int pret);
    std::string get_nume();
    ~Produs();
    void se_gaseste_in(Magazin &m);
    friend std::ostream &operator<<(std::ostream &os,const Produs &produs);
};
typedef std::tuple<Produs, int> produs_cantitate;

class Produs_redus : public Produs{
    int reducere;
public:
    void set_reducere(int val);
    int pret_dupa_reducere();
};

class Magazin{
protected:
    std::string nume;
//    std::string adresa;
    std::vector<produs_cantitate> produse;
    int capacitate_maxima;
public:
    Magazin(std::string nume, std::vector<produs_cantitate> produse, int capacitate);
    ~Magazin();
    void primeste_marfa(Furnizor &f);
//    void set_capacitate(int val);
    virtual int get_capacitate();
    bool exista(Produs &p);
    bool e_disponibil(Produs &p);
    std::vector<std::tuple<Produs, int>>& get_produse();
};

class Furnizor{
    std::string nume;
public:
    Furnizor(std::string nume);
    ~Furnizor();
    void livreaza(Magazin &magazin);
};
#endif
