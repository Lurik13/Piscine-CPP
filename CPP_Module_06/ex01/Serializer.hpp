#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include <cstdlib>

typedef struct Data
{
	int value;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &src);
	
	public:
		virtual ~Serializer() = 0;
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
