// main.cpp
#include "Pipeline.h"
#include "CompressorStation.h"
#include "Logger.h"
#include "FileOperations.h"
#include <iostream>
#include <regex>
#include <vector>
#include <unordered_map>

template <typename T>
void displayFilteredByName(const std::vector<T>& items, const std::string& filterName) {
    bool found = false;
    for (const auto& item : items) {
        if (item.getName().find(filterName) != std::string::npos) {
            item.output();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No items found with name containing: " << filterName << std::endl;
    }
    bool edit_choise{};
    /*std::cout<<"Do you want to edit these elements?(0/1)"<<std::endl;
    std::cin>>edit_choise;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        edit_choise = false;       
    }
    else {
        edit_choise = true;
        break;
    }
    if (edit_choise) {
    for (const auto& item : items) {
        if (item.getName().find(filterName) != std::string::npos) {
            item.edit();
            found = true;
        }
    } 
    }*/

}

// сделать нормально ID через static int
// сделать public setter getter и функции
int main() {
    int current_id = 0;
    std::vector<Pipeline> pipelines;
    std::vector<CompressorStation> stations;

    std::string choe;
    while (true) {
        system("cls");
        std::cout << "1. Add Pipeline\n2. Add Compressor Station\n3. View All\n4. Edit Pipeline\n5. Edit Compressor Station\n6. Save Data\n7. Load Data\n8. Filter by name\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choe;
        char choice = choe[0];

        if (choice == '1') {
            Pipeline p("", 0, 0, false);
            p.input();
            pipelines.push_back(p);
            
        } else if (choice == '2') {
            CompressorStation s("", -1, -1, -1);
            s.input();
            stations.push_back(s);
        } else if (choice == '3') {
            std::cout << "Pipelines:\n";
            for (const auto& p : pipelines) p.output();
            std::cout << "\nCompressor Stations:\n";
            for (const auto& s : stations) s.output();
            system("pause");
        } else if (choice == '4') {
            std::string id;
            std::cout << "Enter Pipes' IDs to edit(Enter IDs separated with , ): ";
            std::cin >> id;
            std::stringstream ss(id);
            std::string numbers;

            for (auto& s : pipelines) {
                while (std::getline(ss, numbers, ',')) {
                    int num = std::stoi(numbers);   
                    std::cout << num << "!!!!!" << std::endl;
                    if (s.getId() == num) {
                        s.edit();
                        break;
                    }  
                }
            }
        } else if (choice == '5') {
            std::string id;
            std::cout << "Enter compressor stations' IDs to edit(Enter IDs separated with , ): ";
            std::cin >> id;
            std::stringstream ss(id);
            std::string numbers;

            for (auto& s : stations) {
                while (std::getline(ss, numbers, ',')) {
                    int num = std::stoi(numbers);    
                    std::cout << num << "!!!!!" << std::endl;
                    if (s.getId() == num) {
                        s.edit();
                        break;
                    }  
                }
            }
        } else if (choice == '6') {
            savePipelines(pipelines, "pipelines.txt");
            saveCompressorStations(stations, "stations.txt");
            Logger::log("Data saved.");
            system("pause");
        } else if (choice == '7') {
            pipelines.clear();
            stations.clear();
            loadPipelines(pipelines, "pipelines.txt");
            loadCompressorStations(stations, "stations.txt");
            Logger::log("Data loaded.");
            system("pause");
        } else if (choice == '0') {
            break;
        } else if (choice == '8') {    
            // Запрос строки для фильтрации от пользователя
            std::string filterName;
            std::cout << "Enter a name (or part of a name) to filter objects by: ";
            std::cin >> filterName;
            //std::getline(std::cin, filterName);

            // Вывод отфильтрованных объектов
            std::cout << "\nFiltered Pipelines:\n";
            displayFilteredByName(pipelines, filterName);

            std::cout << "\nFiltered Compressor Stations:\n";
            displayFilteredByName(stations, filterName);
            system("pause");
        }
        
        else {
            std::cout << "Input error. Try again." << std::endl;
        }
    }

    return 0;
}
