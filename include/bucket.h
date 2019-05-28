#ifndef BUCKET_H_
#define BUCKET_H_

#include <iostream>
#include <string>
#include <vector>

class Bucket {
public:
    int id;
    std::string name;
    int age;
    std::string nationality;
    Bucket *next;
    int count;
public:
	Bucket();
    Bucket(int id, std::string name);
	Bucket(const Bucket& bucket);
};

#endif
