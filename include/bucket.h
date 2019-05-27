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
    Bucket(int _id, std::string _name, Bucket *_next) {
        this->id = _id;
        this->name = _name;
        this->next = _next;
        this->count = 0;
    };
};