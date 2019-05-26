#include "register.h"
#include "fileorganizer.h"

void FileOrganizer::writeRecord(Register record)
{
	// TODO : Open this->filename and write raw record

	std::ofstream fp;
	fp.open(this->filename_, std::ios::out | std::ios::app);

	fp.write((char*)&record, sizeof(record));
	fp.close();

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
