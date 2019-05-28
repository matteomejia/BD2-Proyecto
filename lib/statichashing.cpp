#include "statichashing.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

StaticHash::StaticHash(std::string filename) {
	// TODO : Replace getline calls (marked below) with variables given from input.
	// This module does not interact with iostream. There is a class that will do.
	// That class will create and manage this class (class Hash)
	// There shouldn't be any call to getline at all in this file.

	std::ifstream hashFile;
    hashFile.open(filename);

    if(hashFile.is_open()){
        std::string temp;
        getline(hashFile, temp); // Replace with input variable
        this->size = std::stoi(temp);
        getline(hashFile, temp); // Replace with input variable
        this->bucketNum = std::stoi(temp);
        getline(hashFile, temp); // Replace with input variable
        fd = std::stoi(temp);
    }

    hashFile.close();
}

StaticHash::StaticHash(std::string filename, int size, int fd) {
	this->size = size;
    this->hashTable.resize(size);
    this->fd = fd;

    for(int i = 0; i < size; i++) {
        Bucket temp(i, std::to_string(i).append(".md"));
        this->hashTable[i] = temp;
    }

    this->bucketNum = size;

    std::ifstream input;
    input.open(filename);

    std::string temp;
    if(input.is_open()){
        while(getline(input, temp)){
            insert(temp);
        }
    }
    input.close();

    std::ofstream output;
    output.open("hash.md");
    if(output.is_open()){
        output << std::to_string(size) << std::endl;
        output << std::to_string(bucketNum) << std::endl;
        output << std::to_string(fd) << std::endl;
    }
    output.close();

    for (int i = 0; i < size; i++) {
        std::ofstream index;
        index.open(std::to_string(i).append("index.md"));
        if(index.is_open()){
            index << (hashTable[i]).name << std::endl;
            Bucket *temp = (hashTable[i]).next;
            while(temp){
                index << temp->name << std::endl;
                temp = temp->next;
            }
        }
        index.close();
    }
}

int StaticHash::hashingFunction(int key) {
	return key % size;
}

bool StaticHash::fullBucket(Bucket *bucket) {
	if(bucket->count < fd) {
		return false;
	}else {
		return true;
	}
}

void StaticHash::insertHash(std::string input){
	Bucket *bucket = new Bucket(hashTable[hashingFunction(std::stoi(input.replace(input.begin(), input.end(), ",", "")))]);

    while(bucket->next != nullptr){
        bucket = bucket->next;
    }

    if(fullBucket(bucket)){
        Bucket *temp = new Bucket(bucketNum, std::to_string(bucketNum).append(".md"));

        bucket->next = temp;
        bucketNum++;

        bucket = temp;
    }

    std::string name = bucket->name;

    std::ofstream output;
    output.open(name, std::ios::app);

    if(output.is_open()){
        output << input << std::endl;
        bucket->count += 1;
    }

    output.close();
}

void StaticHash::insert(std::string input){
    int id = hashingFunction(std::stoi(input.replace(input.begin(), input.end(), ",", "")));

    std::ifstream bucketTable;
    bucketTable.open(std::to_string(id).append("_index.md"));
    std::string bucket;
	std::string temp;
    if(bucketTable.is_open()){
        while(getline(bucketTable, temp)){
            bucket = temp;
        }
    }
    bucketTable.close();

    std::ifstream bucketFile;
    int count = 0;
    bucketFile.open(bucket);
    if(bucketFile.is_open()){
        while(getline(bucketFile,temp))
            count++;
        bucketFile.close();
        std::ofstream newBucketFile;
        if (count < fd){
            newBucketFile.open(bucket, std::ios::app);
            if(newBucketFile.is_open()){   
                newBucketFile << input << std::endl;
            }
            newBucketFile.close();
        }
        else{
            newBucketFile.open(std::to_string(bucketNum).append(".md"));
            if(newBucketFile.is_open()){
            	newBucketFile << input << std::endl;
            	std::ofstream index;
            	index.open(std::to_string(id).append("_index.md"), std::ios::app);
            	if(index.is_open()) {
					index << std::to_string(bucketNum).append(".md") << std::endl;
					bucketNum++;
				}
            	index.close();
            }
            newBucketFile.close();
		    std::ofstream hashFile;
	        hashFile.open("hash.md");
            if(hashFile.is_open()){
                hashFile << std::to_string(size) << std::endl;
                hashFile << std::to_string(bucketNum) << std::endl;
                hashFile << std::to_string(fd) << std::endl;
            }
		    hashFile.close();
        }
    }
}

std::string StaticHash::search(int key) {
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
                        index.close();
                        searchFile.close();
						return temp;
					}
				}
			}
		}
	}
	index.close();
	return "ERROR"; // TODO : Replace with exception.
}
