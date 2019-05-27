#include "bucket.h"

Bucket::Bucket()
{
	this->id = -1;
	this->name = "";
	this->next = nullptr;
	this->count = 0;
}

Bucket::Bucket(int id, std::string name)
{
    this->id = id;
    this->name = name;
    this->next = nullptr;
    this->count = 0;
}

Bucket::Bucket(const Bucket& bucket)
{
	this->id = bucket.id;
	this->name = bucket.name;
	this->next = bucket.next;
	this->count = bucket.count;
}
