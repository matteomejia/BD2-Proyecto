#ifndef STATIC_HASHING_H_
#define STATIC_HASHING_H_

#include "bucket.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// TODO : Refactor. Give a more descriptive name for the class.

class Hash{
private:
    int size;
    int fd;
    int bucketNum = 0;
    std::vector<Bucket> hashTable;

public:
	Hash(std::string filename);
    Hash(int size, int fd, std::string filename);
    int hashingFunction(int key);
    bool fullBucket(Bucket *bucket);
    void insertHash(std::string input);
	void insert(std::string input);
    std::string search(int key);
};

#endif
