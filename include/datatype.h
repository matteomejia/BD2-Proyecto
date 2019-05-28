#ifndef DATA_TYPE_H_
#define DATA_TYPE_H_

#include <iostream>

//Unused file, meant for cross-implementation of file organizations

template <typename T>
class DataType
{
	typedef DataType<T> self;

protected:
	T data_;

public:
	DataType();
	DataType(const DataType& container);

	friend std::ostream &operator<< (std::ostream &os, const self &container);
	friend std::istream &operator>> (std::istream &is, const self &container);
};

#endif
