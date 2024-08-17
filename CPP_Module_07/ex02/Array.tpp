#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), array_size(n)
{
}

template<typename T>
Array<T>::Array(const Array &src) : array(src.array), array_size(src.array_size)
{
	*this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	this->array_size = src.array_size;
	this->array = new T[this->array_size];
	for (unsigned int i = 0; i < this->array_size; i++)
		this->array[i] = src.array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= this->array_size)
		throw(std::runtime_error("Wrong index!"));
	return (this->array[i]);
}

template<typename T>
Array<T>::~Array()
{
	if (this->array)
		delete [] this->array;
}

template<typename T>
void Array<T>::printArray()
{
	for (unsigned int i = 0; i < array_size; i++)
		std::cout << this->array[i] << " ";
	std::cout << std::endl;
}

template<typename T>
unsigned int Array<T>::size()
{
	return (this->array_size);
}
