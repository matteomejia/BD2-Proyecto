#ifndef B_PLUS_TREE_INDEX_H_
#define B_PLUS_TREE_INDEX_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class BPlusTreeIndex : public FileOrganizer
{
// TODO : Define variables and methods

	void writeRecord(Register record) override;
	Register readRecord(int index) override;

public:
	BPlusTreeIndex(std::string filename);

	void insert(Register record) override;
	Register search(int record_id) override;
};

#endif
