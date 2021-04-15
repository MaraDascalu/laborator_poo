//
//  main.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#include <iostream>
#include "Furnizor_Magazin_Produs.h"
#include "Magazin_de_Cartier.h"
#include "Cumparator.h"
#include "Comanda.h"
#include "Cumparator_fidel.h"


int main(int argc, const char * argv[]) {
    Produs produs1("stilou", 20), produs2("pix", 10), produs3("radiera", 5), produs4("caiet", 17);
    Magazin magazin("Librarie", {{produs1, 3}, {produs2, 0}, {produs3, 7}}, 20);
    Furnizor f("nume");
    Cumparator cumparator1("nume", 752, 2233);
    Comanda cmd(111, 0,{{produs1, 3}, {produs2, 1}} ,cumparator1);
    
    
    //Metode Magazin
    int capacitate = magazin.get_capacitate();
    std::cout<<"Capacitate magazin: "<<capacitate<<"\n";
    std::vector<produs_cantitate> produse = magazin.get_produse();
    std::cout<<"Produse magazin:\n";
    for (auto & produs : produse)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    bool exista_produs = magazin.exista(produs1);
    std::cout<<"Exista produs1: "<<exista_produs<<"\n";
    bool stoc = magazin.e_disponibil(produs2);
    std::cout<<"Disponibilitate produs1: "<<stoc<<"\n";
//    magazin.primeste_marfa(f);
    
    //Metode Produs
    produs1.se_gaseste_in(magazin);
    std::string nume = produs1.get_nume();
    std::cout<<"Nume produs1: "<<nume<<"\n";
    
    //Metode Frunizor
//    f.livreaza(magazin);
    bool stoc1 = magazin.e_disponibil(produs2);
    std::cout<<"Disponibilitate produus2: "<<stoc1<<"\n";
    
    //Metode Comanda
    std::vector<produs_cantitate> lista_comanda = cmd.get_lista();
    std::cout<<"Lista produse din comanda:\n";
    for (auto& produs: lista_comanda)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    
    //Metode Cumparator
    Cumparator cumparator2(cumparator1);
    std::cout<<"Cumparator 2: "<<cumparator2;
    produs_cantitate produs_comanda_add = {produs2, 3};
    cumparator2.adauga_produs(cmd, produs_comanda_add, magazin);
    std::vector<produs_cantitate> lista_comanda1 = cmd.get_lista();
    std::cout<<"Lista produse comanda actualizata:\n";
    for (auto& produs: lista_comanda1)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    produs_cantitate produs_comanda_el = {produs1, 1};
    cumparator2.elimina_produs(cmd, produs_comanda_el);
    std::vector<produs_cantitate> lista_comanda2 = cmd.get_lista();
    std::cout<<"Lista produse comanda actualizata:\n";
    for (auto& produs: lista_comanda2)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    Magazin_de_Cartier magazin1("LA Magazin", {{produs1, 5}, {produs2, 1}, {produs4, 5} }, magazin.get_capacitate());
    capacitate = magazin1.get_capacitate();
    std::cout<<"Capacitate magazin de cartier: "<<capacitate<<"\n";
    
}
