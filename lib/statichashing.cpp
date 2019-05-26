#include "register.h"
#include "statichashing.h"

StaticHashing::StaticHashing(std::string filename)
{
	this->filename_ = filename;

	// TODO : Initialize static hash table
}

void StaticHashing::insert(Register record)
{
	// TODO : Insert record into table
}

Register StaticHashing::search(int record_id)
{
	// TODO : Find and return register with id = record_id

	return Register();
}
