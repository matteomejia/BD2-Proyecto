#include <iostream>
#include <string>
#include <vector>

class Bucket{
public:
    int id;
    std::string name;
    Bucket *next;
    int count;
public:
    Bucket(int id, std::string name) {
        this->id = id;
        this->name = name;
        this->next = nullptr;
        this->count = 0;
    }
};