#include "register.h"
#include "randomfile.h"

RandomFile::RandomFile(std::string filename) {
	this->filename_ = filename;

	// TODO : Initialize random file
}

void RandomFile::writeRecord(Register record) {
}
	// TODO : Open this->filename and write raw record

Register RandomFile::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index

	return Register();
}

void RandomFile::insert(Register record) {
	// TODO : Insert record into table
}

Register RandomFile::search(int record_id) {
	// TODO : Find and return register with id = record_id

	return Register();
}
