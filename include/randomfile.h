#ifndef RANDOM_FILE_H_
#define RANDOM_FILE_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class RandomFile : public FileOrganizer {
// TODO : Define variables and methods

	void writeRecord(Register record) override;
	Register readRecord(int index) override;

public:
	RandomFile(std::string filename);

	void insert(Register record) override;
	Register search(int record_id) override;
};

#endif
