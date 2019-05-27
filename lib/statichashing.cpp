#include "statichashing.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

Hash::Hash(std::string filename) {
	ifstream hashFile;
    hashFile.open(filename);

    if(hashFile.is_open()){
        string temp;
        getline(hashFile, temp);
        this->size = std::stoi(temp);
        getline(hashFile, temp);
        this->bucketNum = std::stoi(temp);
        getline(hashFile, temp);
        fd = std::stoi(temp);
    }

    hashFile.close();
}

Hash::Hash(int size, int fd, std::string filename) {
	this->size = size;
    this->hashTable = new Bucket[size];
    this->fd = fd;

    for(int i = 0; i < size; i++) {
        Bucket temp;
        temp->id = i;
        temp->name = to_string(i).append(".md");

        this->hashTable[i] = temp;
    }

    this->bucketNum = size;

    ifstream input;
    input.open(filename);

    string temp;
    if(input.is_open()){
        while(getline(input,temp)){
            insert(temp);
        }
    }
    input.close();

    ofstream output;
    output.open("hash.md");
    if(output.is_open()){
        output << to_string(size) << endl;
        output << to_string(bucketNum) << endl;
        output << to_string(fd) << endl;
    }
    output.close();

    for (int i = 0; i < size; i++) {
        ofstream index;
        index.open(to_string(i).append("index.md"));
        if(index.is_open()){
            index << (hashTable[i])->name << endl;
            Bucket *temp = (hashTable[i])->overflow;
            while(temp){
                index << temp->name << endl;
                temp = temp->overflow;
            }
        }
        index.close();
    }
}

int hashingFunction(int key) {
	return key % size;
}

bool fullBucket(Bucket *bucket) {
	if(bucket->count < fd) {
		return false;
	}else {
		return true;
	}
}

void insert(string insert) {
	Bucket *bucket = hashTable[hashingFunction(std::stoi(insert.substr(0, insert.find(","))))];

	while(bucket->overflow != nullptr) {
		bucket = bucket->overflow;
	}

	if(fullBucket(bucket)) {
		Bucket *temp = new Bucket();
		temp->id = bucketNum;
		temp->name = std::to_string(bucketNum).append(".md");
		bucket->overflow = temp;
		bucketNum++;
		bucket = temp;
	}

	std::string bucketFile = bucket->name;

	std::ofstream output;
	output.open(bucketFile, std::ios::app);

	if(output.is_open()) {
		output << insert << std::endl;
		bucket->count += 1;
	}

	output.close();
}

std::string search(int key) {
	int id = hashingFunction(key);
	std::ifstream index;
	index.open(std::to_string(id).append("_index.md"));

	if(index.is_open()) {
		std::string bucket;
		while(getline(index, bucket)) {
			std::ifstream searchFile;
			searchFile.open(bucket);

			if(searchFile.is_open()) {
				std::string temp;
				while(getline(searchFile, temp)) {
					if(temp.find(std::to_string(key)) != std::string::npos) {
						return temp;
					}
				}
			}
		}
	}
	index.close();
	return "ERROR";
}