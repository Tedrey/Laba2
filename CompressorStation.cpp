// CompressorStation.cpp
#include "CompressorStation.h"
#include <iostream>

int CompressorStation::current_id;

CompressorStation::CompressorStation(std::string name, int total_shops, int shops_in_work, double efficiency)
    : id(current_id++), name(name), total_shops(total_shops), shops_in_work(shops_in_work), efficiency(efficiency) {}
/*
void CompressorStation::setId(int newid) {id = newid;}
void CompressorStation::setName(const std::string& newname) {name = newname;}
void CompressorStation::setNumCompressors(int newnumCompressors) {numCompressors = newnumCompressors;}
void CompressorStation::setNumActiveCompressors(int newnumActiveCompressors) {numActiveCompressors = newnumActiveCompressors;}
void CompressorStation::setEfficiency(double newefficiency) {efficiency = newefficiency;}

int CompressorStation::getId() const {return id;}
std::string CompressorStation::getName() const {return name;}
int CompressorStation::getNumCompressors() const {return total_shops;}
int CompressorStation::getNumActiveCompressors() const {return shops_in_work;}
double CompressorStation::getEfficiency() const {return efficiency;}*/

void CompressorStation::input() {
    system("cls");
    output();
    std::cout << "Enter pipeline name: ";
    std::cin >> name;
    CompressorStation::setName(name);
    system("cls");
    output();
    do {
        //int total_shops = CompressorStation::getNumCompressors();
        std::cout<<"Enter the amount of shops in total  of "<<total_shops<<" :";
        std::cin>>total_shops;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            CompressorStation::setNumCompressors(-1);
        }
        else {
            CompressorStation::setNumCompressors(total_shops);
        }
        system("cls");
        output();
    } while (total_shops <= 0);
    do {
        //int shops_in_work = CompressorStation::getNumActiveCompressors();
        std::cout<<"Enter the amount of working shops of "<<CompressorStation::getName()<<" :";
        std::cin>>shops_in_work;
        if (std::cin.fail() || shops_in_work > CompressorStation::getNumCompressors()) {
            std::cin.clear();
            std::cin.ignore();
            shops_in_work = -1;
        }
        else {
            CompressorStation::setNumActiveCompressors(shops_in_work);
        }
        system("cls");
        output(); 
    } while (shops_in_work <= 0);
    do {
        //double efficiency{};
        std::cout<<"Enter efficiency  of the "<<CompressorStation::getNumActiveCompressors()<<" :";
        std::cin>>efficiency;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            total_shops = -1;
        }
        else {
            CompressorStation::setEfficiency(efficiency);
        }
        system("cls");
        output(); 
    } while (efficiency <= 0);
}

void CompressorStation::output() const {
    std::cout<<"CS ID:               "<<CompressorStation::getId()<<"\n";
    std::cout<<"CS name:            '"<<CompressorStation::getName()<<"'\n";
    std::cout<<"TShops total:        "<<CompressorStation::getNumCompressors()<<"\n";
    std::cout<<"Shops in work:       "<<CompressorStation::getNumActiveCompressors()<<"\n";
    std::cout<<"Effciency:           " <<CompressorStation::getEfficiency()<< std::endl;
    std::cout<<" ---------------------- "<<std::endl;
}
void CompressorStation::edit() {
    if (shops_in_work + 1 < total_shops) {
        ++shops_in_work;
    }
    else {
        --shops_in_work;
    }
}

void CompressorStation::resetId() {
    current_id = 0;
}
