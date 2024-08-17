#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

template<typename T>
class Array
{
	public:
		// Array();
		Array(unsigned int n = 0);
		Array(const Array &src);
		Array &operator=(const Array &src);
		T &operator[](unsigned int i);
		~Array();

		void printArray();
		unsigned int size();

	private:
		T *array;
		unsigned int array_size;
};
