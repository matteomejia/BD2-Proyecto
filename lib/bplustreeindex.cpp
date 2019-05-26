#include <iostream>

#include "register.h"
#include "bplustreeindex.h"

BPlusTreeIndex::BPlusTreeIndex(std::string filename) {
	filename_ = filename;

	// TODO : Initialize B+Tree index
}

void BPlusTreeIndex::writeRecord(Register record) {
	// TODO : Open this->filename and write raw record
}

Register BPlusTreeIndex::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index

	return Register();
}

void BPlusTreeIndex::insert(Register record) {
	// TODO : Insert record into table
}

Register BPlusTreeIndex::search(int record_id) {
	// TODO : Find and return register with id = record_id

	return Register();
}
