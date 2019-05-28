#ifndef STATIC_HASHING_H_
#define STATIC_HASHING_H_

#include "bucket.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class StaticHash{
private:
    int size;
    int fd;
    int bucketNum = 0;
    std::vector<Bucket> hashTable;

public:
	StaticHash(std::string filename);
    StaticHash(std::string filename, int size, int fd);
    int hashingFunction(int key);
    bool fullBucket(Bucket *bucket);
    void insertHash(std::string input);
	void insert(std::string input);
    std::string search(int key);
};

#endif
