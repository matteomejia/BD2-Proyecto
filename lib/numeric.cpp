#include <iostream>

#include "numeric.h"

template <typename T>
std::ostream &operator<< (std::ostream &os, const DataType<T> &container)
{
	os << container;

	return os;
}

template <typename T>
std::istream &operator>> (std::istream &is, const DataType<T> &container)
{
	is >> container;

	return is;
}
