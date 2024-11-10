// CompressorStation.h
#ifndef COMPRESSORSTATION_H
#define COMPRESSORSTATION_H

#include <string>
#include <iostream>

class CompressorStation {
private:
    int id;
    std::string name;
    int total_shops;
    int shops_in_work;
    double efficiency;
public:
    static int current_id;
    // сеттеры
    void setId(int id) { this->id = id; }
    void setName(const std::string& name) { this->name = name; }
    void setNumCompressors(int numCompressors) { this->total_shops = numCompressors; }
    void setNumActiveCompressors(int numActiveCompressors) { this->shops_in_work = numActiveCompressors; }
    void setEfficiency(double efficiency) { this->efficiency = efficiency; }

    // геттеры
    int getId() const { return id; }
    std::string getName() const { return name; }
    int getNumCompressors() const { return total_shops; }
    int getNumActiveCompressors() const { return shops_in_work; }
    double getEfficiency() const { return efficiency; }

    CompressorStation(std::string name, int total_shops, int shops_in_work, double efficiency);
    void input();
    void output() const;
    void edit();
    static void resetId();
};

#endif
