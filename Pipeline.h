// Pipeline.h
#ifndef PIPELINE_H
#define PIPELINE_H

#include <string>
#include <iostream>

class Pipeline {
private:
    int id;
    std::string name;
    double length;
    double diameter;
    bool in_repair;
public:
    static int current_id;
    //сеттеры
    void setId(int newId);
    void setName(const std::string& newName);
    void setLength(double newLength);
    void setDiameter(double newDiameter);
    void setInRepair(bool repairStatus);

    // Геттеры
    int getId() const;
    std::string getName() const;
    double getLength() const;
    double getDiameter() const;
    bool isInRepair() const;



    Pipeline(std::string name, double length, double diameter, bool in_repair);
    void input();
    void output() const;
    void edit();
    static void resetId();
};

#endif
