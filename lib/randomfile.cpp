#include "../include/register.h"
#include "../include/randomfile.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

RandomFile::RandomFile(std::string filename) {
	this->filename_ = filename;
	// TODO : Initialize random file

}

void RandomFile::writeRecord(Register record) {
	// TODO : Open this->filename and write raw record
	std::ofstream fp;
	fp.open(this->filename_, std::ios::out | std::ios::app);
	record.getData();

	fp.write((char*)&record, sizeof(record));
	fp.close();

}

void RandomFile::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index
	
}

void RandomFile::insert(Register record) {
	// TODO : Insert record into table

}

Register RandomFile::search(int record_id) {
	// TODO : Find and return register with id = record_id
	std::ifstream fp;
	
	int found = 0;
	char n[20];
	Register temp;

	std::cout << "Enter ID: " << std::endl;
	std::cin >> n;

	fp.open(filename_, std::ios::in);
	fp.read((char*)&temp, sizeof(temp));

	if(strcmp(temp.getID(), n) == 0) {
		temp.showData();
		found = 1;
	}
	fp.close();
}
