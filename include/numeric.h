#ifndef NUMERIC_H_
#define NUMERIC_H_

#include <iostream>

#include "datatype.h"

//Unused file meant for cross-compatibility

template <typename T>
class Numeric : public DataType<T>
{
	typedef Numeric<T> self;

public:
	friend std::ostream &operator<< (std::ostream &os, const self &container);
	friend std::istream &operator>> (std::istream &is, const self &container);
};

typedef Numeric<int> Integer;
typedef Numeric<float> Float;

#endif
