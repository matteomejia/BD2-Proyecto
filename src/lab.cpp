#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

void parseCSV(std::ifstream &file, std::vector<std::vector<std::string>> &csv)
{
    std::string line;
    while(std::getline(file,line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while(std::getline(ss , cell, ','))
        {
            row.push_back(cell);
        }

        csv.push_back(row);
    }
}

int main(void) {
    std::ifstream file("fifa19_data.csv");

    std::vector<std::vector<std::string>> csv;

    parseCSV(file, csv);

    for (auto a : csv) {
        for (auto b : a) {
            std::cout << b << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}