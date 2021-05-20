//
//  main.cpp
//  Proiect_poo
//
//  Created by Mara Dascalu on 10/03/2021.
//

#include <iostream>
#include "Furnizor_Magazin_Produs.h"
#include "Magazin_de_Cartier.h"
#include "Produs_redus.h"
#include "Cumparator.h"
#include "Comanda.h"
#include "Cumparator_fidel.h"


int main(int argc, const char * argv[]) {
    Produs produs1("stilou", 20), produs2("pix", 10), produs3("radiera", 5), produs4("caiet", 17);
    produs_cantitate prod1 = {produs1, 3}, prod2 = {produs2, 7}, prod3 = {produs3, 10}, prod4 = {produs4, 1};
    std::vector<std::unique_ptr<produs_cantitate>> vector_produse;
    vector_produse.emplace_back(std::make_unique<produs_cantitate>(prod1));
    vector_produse.emplace_back(std::make_unique<produs_cantitate>(prod2));
    vector_produse.emplace_back(std::make_unique<produs_cantitate>(prod3));
    vector_produse.emplace_back(std::make_unique<produs_cantitate>(prod4));
    Magazin magazin("Librarie", std::move(vector_produse) , 20);
    Furnizor f("nume");
    Cumparator cumparator1("nume", 752, 2233);
    Comanda cmd(111, 0,{} ,std::make_unique<Cumparator>(cumparator1));
    
    //Metode Magazin
    int capacitate = magazin.get_capacitate();
    std::cout<<"Capacitate magazin: "<<capacitate<<"\n\n";
    std::vector<std::unique_ptr<produs_cantitate>> &produse = magazin.get_produse();
    std::cout<<"Produse magazin:\n";
    for (auto & produs : produse)
        std::cout<<std::get<0>(*produs)<<" "<<std::get<1>(*produs)<<"\n";
    std::cout<<"\n";
    bool exista_produs = magazin.exista(produs1);
    std::cout<<"Exista produs1: "<<exista_produs<<"\n\n";
    bool stoc = magazin.e_disponibil(produs2);
    std::cout<<"Disponibilitate produs1: "<<stoc<<"\n\n";
//    magazin.primeste_marfa(f);
    
    //Metode Produs
    produs1.se_gaseste_in(magazin);
    std::string nume = produs1.get_nume();
    std::cout<<"Nume produs1: "<<nume<<"\n\n";
    
    //Metode Frunizor
//    f.livreaza(magazin);
    bool stoc1 = magazin.e_disponibil(produs2);
    std::cout<<"Disponibilitate produs2: "<<stoc1<<"\n\n";
    
    //Metode Comanda
    std::vector<produs_cantitate> lista_comanda = cmd.get_lista();
    std::cout<<"Lista produse din comanda:\n";
    for (auto& produs: lista_comanda)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    std::cout<<"\n";
    
    //Metode Cumparator
    Cumparator cumparator2(cumparator1);
    std::cout<<"Cumparator 2: "<<cumparator2<<"\n\n";

    try{
        produs_cantitate produs_comanda_add = {produs2, 3};
        cumparator2.adauga_produs(cmd, produs_comanda_add, magazin);
    }
    catch(std::invalid_argument exceptie){
        std::cout<<exceptie.what();
    }
    std::vector<produs_cantitate> lista_comanda1 = cmd.get_lista();
    std::cout<<"Lista produse comanda actualizata:\n";
    for (auto& produs: lista_comanda1)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
//    std::cout<<"\n";
    std::cout<<"Produse magazin:\n";
    for (auto & produs : produse)
        std::cout<<std::get<0>(*produs)<<" "<<std::get<1>(*produs)<<"\n";
    std::cout<<"\n";
    produs_cantitate produs_comanda_el = {produs1, 1};
    cumparator2.elimina_produs(cmd, produs_comanda_el, magazin);
    std::vector<produs_cantitate> lista_comanda2 = cmd.get_lista();
    std::cout<<"Lista produse comanda actualizata:\n";
    for (auto& produs: lista_comanda2)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    std::cout<<"Produse magazin:\n";
    for (auto & produs : produse)
        std::cout<<std::get<0>(*produs)<<" "<<std::get<1>(*produs)<<"\n";
    std::cout<<"\n";
    std::cout<<"Total comanda: "<<cmd.pret_total()<<"\n\n";
    
    //Metode Magazin_de_Cartier
    vector_produse.emplace_back(std::make_unique<produs_cantitate>(prod4));
    Magazin_de_Cartier magazin1("LA Magazin", std::move(vector_produse), magazin.get_capacitate());
    capacitate = magazin1.get_capacitate();
    std::cout<<"Capacitate magazin de cartier: "<<capacitate<<"\n\n";
    
    //Metode Produs_redus
    Produs_redus produs1_r("penar", 30);
    produs1_r.set_reducere(10);
    std::cout<<"Pretul produsului dupa reducere: "<<produs1_r.get_pret()<<"\n\n";
    
    Cumparator* cumparator = new Cumparator_fidel("Mihai", 44275, 276, 5);
    Comanda cmd2(112,0,{}, std::make_unique<Cumparator_fidel>("Mihai", 44275, 276, 5));
    std::cout<<cumparator->get_discount()<<"\n\n";
    lista_comanda = cmd2.get_lista();
    std::cout<<"Lista produse din comanda2:\n";
    for (auto& produs: lista_comanda)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    std::cout<<"\n";
    
    try{
        produs_cantitate prod1_cmd2_add = {produs3, 5}, prod2_cmd2_add = {produs4, 10};
        cumparator->adauga_produs(cmd2, prod1_cmd2_add, magazin);
        cumparator->adauga_produs(cmd2, prod2_cmd2_add, magazin);
    }catch(std::invalid_argument exceptie){
        std::cout<<exceptie.what()<<"\n";
    }
    lista_comanda = cmd2.get_lista();
    std::cout<<"Lista produse din comanda2:\n";
    for (auto& produs: lista_comanda)
        std::cout<<std::get<0>(produs)<<" "<<std::get<1>(produs)<<"\n";
    std::cout<<"\n";
    std::cout<<cmd2.pret_total()<<"\n";
    delete cumparator;
    
}
