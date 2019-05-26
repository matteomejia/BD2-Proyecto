#ifndef FILE_ORGANIZER_H_
#define FILE_ORGANIZER_H_

#include <iostream>

#include "register.h"
#include <iostream>

class FileOrganizer
{
protected:
	std::string filename_;

	virtual void writeRecord(Register record);
	virtual Register readRecord(int index);

public:
	FileOrganizer() = default;
	virtual void insert(Register record) = 0;
	virtual Register search(int record_id) = 0;
};

#endif
