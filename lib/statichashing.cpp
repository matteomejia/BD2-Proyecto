#include "register.h"
#include "statichashing.h"

StaticHashing::StaticHashing(std::string filename) {
	this->filename_ = filename;

	// TODO : Initialize static hash table
}

void StaticHashing::writeRecord(Register record) {
	// TODO : Open this->filename and write raw record
}

Register StaticHashing::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index

	return Register();
}

void StaticHashing::insert(Register record) {
	// TODO : Insert record into table
}

Register StaticHashing::search(int record_id) {
	// TODO : Find and return register with id = record_id

	return Register();
}
