#include "datatype.h"

//Unused

template <typename T>
DataType<T>::DataType()
{

}

template <typename T>
DataType<T>::DataType(const DataType<T> &container)
{
	this->data_ = container->data_;
}
