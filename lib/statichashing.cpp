#include "register.h"
#include "statichashing.h"

StaticHaching::StaticHaching(std::string filename) {
	this->filename_ = filename;

	// TODO : Initialize static hash table
}

void StaticHashing::writeRecord(Record record) {
	// TODO : Open this->filename and write raw record
}

void StaticHashing::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index
}

void StaticHashing::insert(Register record) {
	// TODO : Insert record into table
}

Register StaticHashing::search(int record_id) {
	// TODO : Find and return register with id = record_id
}
