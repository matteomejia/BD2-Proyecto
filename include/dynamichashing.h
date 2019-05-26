#ifndef DYNAMIC_HASHING_H_
#define DYNAMIC_HASHING_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class DynamicHashing : public FileOrganizer
{
// TODO : Define variables and methods

	void writeRecord(Register record) override;
	Register readRecord(int index) override;

public:
	DynamicHashing(std::string filename);

	void insert(Register record) override;
	Register search(int record_id) override;
};

#endif
