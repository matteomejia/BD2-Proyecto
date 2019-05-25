#include "record.h"
#include "bplustreeindex.h"

BPlusTreeIndex::BPlusTreeIndex(std::string filename) {
	this->filename_ = filename;

	// TODO : Initialize B+Tree index
}

void BPlusTreeIndex::writeRecord(Record record) {
	// TODO : Open this->filename and write raw record
}

void BPlusTreeIndex::readRecord(int index) {
	// TODO : Open this->filename and read raw record in position index
}

void BPlusTreeIndex::insert(Register record) {
	// TODO : Insert record into table
}

Register BPlusTreeIndex::search(int record_id) {
	// TODO : Find and return register with id = record_id
}
