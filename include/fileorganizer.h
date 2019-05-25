#ifndef FILE_ORGANIZER_H_
#define FILE_ORGANIZER_H_

#include "register.h"

class FileOrganizer {
protected:
	std::string filename_;

	void writeRecord(Record record);
	Register readRecord(int index);

public:
	void insert(Register record);
	Register search(int record_id);
};

#endif