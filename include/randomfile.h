#ifndef RANDOM_FILE_H_
#define RANDOM_FILE_H_

#include "register.h"
#include "fileorganizer.h"

class RandomFile : public FileOrganizer {
// TODO : Define variables and methods

public:
	RandomFile(std::string filename);
	void writeRecord(Register record);
	void readRecord(int index);
	void insert(Register record);
	Register search(int record_id);
};

#endif
