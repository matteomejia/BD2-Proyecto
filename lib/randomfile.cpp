#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "register.h"
#include "randomfile.h"

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

RandomFile::RandomFile(std::string filename, std::string outfile)
{
	this->filename_ = filename;
	// TODO : Initialize random file
	std::ifstream fp;
	fp.open(filename, std::ios::in | std::ios::app);

	std::vector<std::vector<std::string>> records;

	parseCSV(fp, records);
	fp.close();

	int x = 1;
	for (std::vector<std::string> row : records) {
		std::pair<int, std::string> pair;
		pair.first = x;
		pair.second = row[0];
		pairs.push_back(pair);
		x++;
	}

	std::ofstream out;
	out.open(outfile, std::ios::out);

	for (std::pair<int, std::string> pair : pairs) {
		std::string line = pair.first + ", " + pair.second + "\n";
		out.write(line, sizeof(line));
	}


}

void RandomFile::insert(Register record)
{
	// TODO : Insert record into table
}

Register RandomFile::search(int record_id)
{
	// TODO : Find and return register with id = record_id
	
	return Register();
}
