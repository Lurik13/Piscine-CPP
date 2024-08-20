#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

#define BLUE RESET "\e[38;2;0;150;250;1m"
#define UNDERLINED "\e[4m"
#define INVERT "\e[7m"
#define RESET "\e[0m"

template<typename T>
typename T::iterator easyfind(T &container, const int &number)
{
	typename T::iterator first = container.begin();
	typename T::iterator last = container.end();
	while (first != last)
	{
		if (*first == number)
			return (first) ;
		++first;
	}
	return (last);
}

template<typename T, typename U>
typename T::iterator better_easyfind(T &container, const U &value)
{
	typename T::iterator first = container.begin();
	typename T::iterator last = container.end();
	while (first != last)
	{
		if (*first == value)
			return (first) ;
		++first;
	}
	return (last);
}