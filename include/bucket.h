#include <iostream>
#include <string>
#include <vector>

class Bucket{
public:
    int id;
    std::string name;
    Bucket *next = nullptr;
    int count = 0;
public:
    Bucket(int id, std::string name, Bucket *next) {
        this->id = id;
        this->name = name;
        this->next = next;
        this->count = 0;
    };
};