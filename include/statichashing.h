#ifndef STATIC_HASHING_H_
#define STATIC_HASHING_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class StaticHashing : public FileOrganizer
{
// TODO : Define variables and methods
public:
	StaticHashing(std::string filename);

	void insert(Register record) override;
	Register search(int record_id) override;
};


#endif
