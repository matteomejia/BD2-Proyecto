#ifndef FILE_ORGANIZER_H_
#define FILE_ORGANIZER_H_

#include <iostream>

#include "register.h"

class FileOrganizer {
protected:
	std::string filename_;

	void writeRecord(Register record);
	Register readRecord(int index);
	void test();

public:
	void insert(Register record);
	Register search(int record_id);
};

#endif
