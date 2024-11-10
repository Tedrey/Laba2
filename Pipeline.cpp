// Pipeline.cpp
#include "Pipeline.h"
#include <iostream>

int Pipeline::current_id;

Pipeline::Pipeline(std::string name, double length, double diameter, bool in_repair) 
    : id(current_id++), name(name), length(length), diameter(diameter), in_repair(in_repair) {}

void Pipeline::setId(int newId) { id = newId; }
void Pipeline::setName(const std::string& newName) { name = newName; }
void Pipeline::setLength(double newLength) { length = newLength; }
void Pipeline::setDiameter(double newDiameter) { diameter = newDiameter; }
void Pipeline::setInRepair(bool repairStatus) { in_repair = repairStatus; }

int Pipeline::getId() const { return id; }
std::string Pipeline::getName() const { return name; }
double Pipeline::getLength() const { return length; }
double Pipeline::getDiameter() const { return diameter; }
bool Pipeline::isInRepair() const { return in_repair; }

void Pipeline::input() {
    system("cls");
    output();
    std::cout << "Enter pipeline name: ";
    std::cin >> name;
    Pipeline::setName(name);
    system("cls");
    output();
    do {
        std::cout<<"Enter the length of the "<<name<<" tube(cannot be 0):";
        std::cin>>length;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            Pipeline::setLength(0);
        }
        else {
            Pipeline::setLength(length);
        }
        system("cls");
        output();
    } while (length == 0);
    do {
        std::cout<<"Enter the diametr of the "<<name<<" tube(cannot be 0):";
        std::cin>>diameter;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            Pipeline::setDiameter(0);
        }
        else {
            Pipeline::setDiameter(diameter);
        }
        system("cls");
        output();
         
    } while (diameter == 0);

    std::cout<<"Enter the state of the "<<Pipeline::getName()<<" (In repairing - 1 Not under repair - 0): ";
    std::cin>>in_repair;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        Pipeline::setInRepair(0);
    }
    else {
        Pipeline::setInRepair(in_repair);
    }
    system("cls");
    output(); ;
}

void Pipeline::output() const {
    std::cout<<"Tube ID:             "<<Pipeline::getId()<<"\n";
    std::cout<<"Tube name:           '"<<Pipeline::getName()<<"'\n";
    std::cout<<"Tube length:         "<<Pipeline::getLength()<<"\n";
    std::cout<<"Diamert of the tube: "<<Pipeline::getDiameter()<<"\n";
    std::cout<<"In repair:           " << (Pipeline::isInRepair() ? "Yes" : "No") << std::endl;
    std::cout<<" ---------------------- "<<std::endl;
}

void Pipeline::edit() {
    Pipeline::setInRepair(-Pipeline::isInRepair());
    
}

void Pipeline::resetId() {
    current_id = 0;
}
