#ifndef RANDOM_FILE_H_
#define RANDOM_FILE_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class RandomFile : public FileOrganizer
{
	// TODO : Define variables and methods
	std::vector<std::pair<int, std::string>> pairs;
public:
	RandomFile(std::string filename, std::string outfile);

	void insert(Register record) override;
	Register search(int record_id) override;
};

#endif
