#include <fstream>

#include "register.h"
#include "fileorganizer.h"

void FileOrganizer::writeRecord(Register record, int index)
{
	// TODO : Open this->filename and write raw record in position index
}

Register FileOrganizer::readRecord(int index)
{
	// TODO : Open this->filename and read raw record in position index

	std::ifstream fp;
	
	int found = 0;
	char n[20];
	Register temp;

	std::cout << "Enter ID: " << std::endl;
	std::cin >> n;

	fp.open(filename_, std::ios::in);
	fp.read((char*)&temp, sizeof(temp));

	fp.close();

	return Register();
}
