#ifndef B_PLUS_TREE_INDEX_H_
#define B_PLUS_TREE_INDEX_H_

#include <iostream>

#include "register.h"
#include "fileorganizer.h"

class BPlusTreeIndex : public FileOrganizer {
// TODO : Define variables and methods

public:
	BPlusTreeIndex(std::string filename);
};

#endif
