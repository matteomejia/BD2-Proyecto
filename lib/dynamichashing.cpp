#include "register.h"
#include "dynamichashing.h"

DynamicHashing::DynamicHashing(std::string filename)
{
	this->filename_ = filename;

	// TODO : Initialize dynamic hash table
}

void DynamicHashing::writeRecord(Register record)
{
	// TODO : Open this->filename and write raw record
}

Register DynamicHashing::readRecord(int index)
{
	// TODO : Open this->filename and read raw record in position index

	return Register();
}

void DynamicHashing::insert(Register record)
{
	// TODO : Insert record into table
}

Register DynamicHashing::search(int record_id)
{
	// TODO : Find and return register with id = record_id

	return Register();
}
