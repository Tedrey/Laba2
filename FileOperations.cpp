// FileOperations.cpp
#include "FileOperations.h"
#include <fstream>
#include <sstream>
#include "Pipeline.h"
#include <algorithm>

void savePipelines(const std::vector<Pipeline>& pipelines, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& pipeline : pipelines) {
        file << pipeline.getId() << '*' << pipeline.getName() << '*' << pipeline.getLength() << '*'
             << pipeline.getDiameter() << '*' << pipeline.isInRepair() << std::endl;
    }
}

void loadPipelines(std::vector<Pipeline>& pipelines, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string name;
        double length, diameter;
        bool in_repair;
        
        ss >> id;
        ss.ignore(); 
        
        std::getline(ss, name, '*');
        
        ss >> length;
        ss.ignore(); 

        ss >> diameter;
        ss.ignore(); 

        ss >> in_repair;
        
        Pipeline p(name, length, diameter, in_repair);
        p.setId(id);
        p.current_id = (p.current_id > id) ? p.current_id : id+1;
        pipelines.push_back(p);
    }
}



void saveCompressorStations(const std::vector<CompressorStation>& stations, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& station : stations) {
        file << station.getId() << '*' << station.getName() << '*' << station.getNumCompressors() << '*'
             << station.getNumActiveCompressors() << '*' << station.getEfficiency() << std::endl;
    }
}

void loadCompressorStations(std::vector<CompressorStation>& stations, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    
        while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id, total_shops, shops_in_work, efficiency;
        std::string name;
        double length, diameter;
        bool in_repair;
        
        ss >> id;
        ss.ignore(); 
        
        std::getline(ss, name, '*');
        
        ss >> total_shops;
        ss.ignore(); 
        

        ss >> shops_in_work;
        ss.ignore(); 
        
        ss >> efficiency;
        
        CompressorStation s(name, total_shops, shops_in_work, efficiency);
        s.setId(id);
        s.current_id = (s.current_id > id) ? s.current_id : id+1;
        stations.push_back(s);
    }
}
